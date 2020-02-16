//
// Created by 毛华伟 on 2020/1/9.
//

#pragma  once

#ifndef APP_IMCONNECTMANAGER_H
#define APP_IMCONNECTMANAGER_H


#include <folly/json.h>


class IMConnectManager
{


public:
    class CallBack;

public:

    virtual ~IMConnectManager()
    {};

    virtual void start() = 0;

    virtual void stop() = 0;

    virtual bool isOpen() = 0;

    virtual void sendMessage(const folly::dynamic &message) = 0;

    virtual void setCallBack(CallBack *callBack) = 0;

    virtual void onMessageReceived(
            const folly::dynamic &message) = 0;


};

class IMConnectManager::CallBack
{


public:
    virtual ~CallBack()
    {};

    virtual void onConnected() = 0;

    virtual void onDesconnected() = 0;

    virtual void onMessageReceive(
            const folly::dynamic &message) = 0;


};


#endif //APP_IMCONNECTMANAGER_H


