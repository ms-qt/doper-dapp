//
// Created by 毛华伟 on 2020/1/9.
//

#ifndef APP_IMCONNECTMANAGERIMPL_H
#define APP_IMCONNECTMANAGERIMPL_H


#include <folly/Executor.h>
#include <folly/io/async/EventBase.h>
#include <rsocket/RSocket.h>
#include <mutex>

#include "IMConnectManager.h"


class ConnectionEvents;


class IMConnectManagerImpl : public IMConnectManager
{
    friend ConnectionEvents;


public:

    IMConnectManagerImpl();

    ~IMConnectManagerImpl();

    void start() override;

    void stop() override;

    bool isOpen() override;

    void setCallBack(CallBack *callBack) override;

    virtual void sendMessage(const folly::dynamic &message) override;

    virtual void onMessageReceived(
            const folly::dynamic &message) override;


private:


    bool isOpen_ = false;
    bool isStarted_ = false;
    CallBack *callBack_;

};


#endif //APP_IMCONNECTMANAGERIMPL_H
