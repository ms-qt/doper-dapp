//
// Created by 毛华伟 on 2020/1/7.
//
#include <iostream>
#include <folly/init/Init.h>
#include <folly/io/async/ScopedEventBaseThread.h>
#include <folly/portability/GFlags.h>
#include "rsocket/RSocket.h"
#include "rsocket/transports/tcp/TcpConnectionFactory.h"
#include "yarpl/Flowable.h"


#include <map>
#include <string>

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QJsonValue>
#include<QDebug>
#include "src/utils/UUIDUtils.h"

#include "src/app/AppQuickViewManager.h"

class IM
{
public :
    void init();

    void requestLoginQrCode();

    static IM *GetInstance();

    static void DeleteInstance();


    bool isConnect = false;


private:
    static IM *instance;
    std::unique_ptr<rsocket::RSocketClient> client_;
    folly::ScopedEventBaseThread worker;
    folly::EventBase eventBase;
    folly::SocketAddress address;

    // 连接
    void connect();

    // 从新连接
    void reconnect();

};


