//
// Created by 毛华伟 on 2020/1/7.
//

#include "IM.h"
#include <src/data/Data.h>

#include <thread>
#include <QThread>

typedef QJsonDocument jsonDocument;


class ConnectionEvents : public rsocket::RSocketConnectionEvents
{
private:
    IM *mIm;
public:
    ConnectionEvents(IM *im)
    {
        mIm = im;
        qDebug() << "ConnectionEvents()";
    }

    void onConnected()
    {
        // 连接上了服务器
        qDebug() << "onConnected()";
        mIm->isConnect = true;
    }

    void onDisconnected(const folly::exception_wrapper &)
    {
        qDebug() << "onDisconnected()";
        mIm->isConnect = false;
    }

    void onClosed(const folly::exception_wrapper &e)
    {
        qDebug() << "onClosed()";
        onDisconnected(e);
    }
};


IM *IM::instance = nullptr;

IM *IM::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new IM();
    }
    return instance;
}


void IM::DeleteInstance()
{
    if (instance != nullptr)
    {
        delete instance;
    }
}


void IM::init()
{
    connect();
}


void IM::requestLoginQrCode()
{

    QJsonObject object;
    object.insert("type", "login-qrcode-register");
    object.insert("qrcode", Data::getInstance().loginQrCodeEnCode);
    object.insert("os", "macos");
    object.insert("uuid", Data::getInstance().uuid);
    jsonDocument document = QJsonDocument(object);
    QString data = QString(document.toJson());

    qDebug() << "数据 : " << data;

    std::map<std::string, std::string> map;
    map[data.toStdString()] = data.toStdString();

    std::shared_ptr<yarpl::flowable::Flowable<rsocket::Payload>> fp = yarpl::flowable::Flowable<std::map<std::string, std::string>>::justN(
            {map})->map(
            [](std::map<std::string, std::string> mapparams)
            {
                std::map<std::string, std::string>::iterator it;
                for (it = mapparams.begin(); it != mapparams.end(); it++)
                {
                    std::cout << it->first << std::endl;
                    return rsocket::Payload(it->first, it->second);
                }
            });

    if (isConnect)
    {
        client_->getRequester()
                ->requestChannel(
                        rsocket::Payload(data.toStdString()),
                        fp
                )
                ->subscribe([this](rsocket::Payload p)
                            {
                                // 只能获取一次
                                QString qJsonStr = QString::fromStdString(p.moveDataToString());
                                qDebug() << "接收数据 data : " << qJsonStr;
                                qDebug() << "接收数据 metadata : " << QString::fromStdString(p.moveMetadataToString());

                                qDebug() << "QString = " << qJsonStr;

                                QJsonDocument documemnt = QJsonDocument::fromJson(qJsonStr.toLocal8Bit().data());
                                QJsonObject object = documemnt.object();
                                QJsonValue resValue = object.value("res");
                                QString res = resValue.toString();
                                qDebug() << "res = " << res;

                                if ("success" == res)
                                {
                                    // success data hide diallog

                                }
                            });
    }
}


void IM::connect()
{
    address.setFromHostPort("192.168.0.43", 8889);
    rsocket::SetupParameters parameters;
    QJsonObject object;

    object.insert("type", "login-app");
    object.insert("os", "macos");
    object.insert("uuid", Data::getInstance().uuid);
    QJsonDocument document = QJsonDocument(object);
    QString data = QString(document.toJson());
    parameters.payload = rsocket::Payload(data.toStdString());


    try
    {
        // 连接服务器
        client_ = rsocket::RSocket::createConnectedClient(
                std::make_unique<rsocket::TcpConnectionFactory>(*worker.getEventBase(), std::move(address)),
                std::move(parameters),
                nullptr,
                std::chrono::seconds(60 * 60 * 24 + 365),//  连接上服务器就不再断开，
                nullptr,
                std::make_shared<ConnectionEvents>(this)
        ).get();
    } catch (std::runtime_error err)
    {
        qDebug() << "connect err : ";

        return;
    }
    requestLoginQrCode();
}


void IM::reconnect()
{


    qDebug() << "reconnect()" << isConnect;

    if (!isConnect)
    {
        folly::makeFuture().via(eventBase.getEventBase()).delayed(std::chrono::seconds(2)).thenValue([this](auto &&)
                                                                                                     {

                                                                                                         qDebug()
                                                                                                                 << "reconnect [](){}";

                                                                                                     });
    }
}
