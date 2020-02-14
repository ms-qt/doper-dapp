//
// Created by 毛华伟 on 2020/1/19.
//

#include "LoginCallBack.h"

LoginCallBack::LoginCallBack()
{
}

LoginCallBack::~LoginCallBack()
{
}

void LoginCallBack::onSuccess(std::string res)
{
    qDebug() << QString::fromStdString(res);
    // 登录成功
    folly::dynamic jobj = folly::parseJson(res);
    std::string login_type = jobj["login_type"].asString();

    // 扫二维登录
    if ("login-qrcode" == login_type)
    {

        //用户名登录
    } else if ("login-username" == login_type)
    {
        std::string username = jobj["username"].asString();
        std::string password = jobj["password"].asString();
        std::string userid = jobj["user_id"].asString();
        std::string access_token = jobj["access_token"].asString();
        std::string refresh_token = jobj["refresh_token"].asString();

        bool auto_login = jobj["auto_login"].asBool();
        bool save_password = jobj["save_password"].asBool();

        CertificateBean *certificateBean = new CertificateBean();

        certificateBean->setUsername(QString::fromStdString(username));
        certificateBean->setPassword(QString::fromStdString(password));
        certificateBean->setUserId(QString::fromStdString(userid));
        certificateBean->setAccessToken(QString::fromStdString(access_token));
        certificateBean->setRefreshToken(QString::fromStdString(refresh_token));
        certificateBean->setAutoLogin(auto_login);
        certificateBean->setSavePassword(save_password);
        certificateBean->setLoginType("login-username");

        CertificateDB *certificateDb = new CertificateDB();
        certificateDb->insert(certificateBean);


        emit UIModelProxy::GetInstance()->loginSuccess();


    }
}

void LoginCallBack::onFailure(std::string res)
{
    //登录失败
}