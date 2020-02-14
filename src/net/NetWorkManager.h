//
// Created by 毛华伟 on 2020/1/16.
//

#ifndef DOPER_DAPP_NETWORKMANAGER_H
#define DOPER_DAPP_NETWORKMANAGER_H

#include <rxcpp/rx.hpp>
#include <rxqt.hpp>
#include <src/app/LoginQuickView.h>

#include <src/tool/ThreadTool.h>

class NetWorkManager
{


public:


    static rxqt::run_loop *m_rxqt_run_loop;

    static NetWorkManager &getInstance()
    {
        static NetWorkManager instance;
        return instance;
    }


    void init(rxqt::run_loop &rxqt_run_loop);


    // app 登录
    void applogin(LoginQuickView *view);


    void test(rxcpp::observe_on_one_worker &mainthread, LoginQuickView &view);


private:
    NetWorkManager()
    {};

    ~NetWorkManager()
    {};

    NetWorkManager(const NetWorkManager &);

    NetWorkManager &operator=(const NetWorkManager &);


};


#endif //DOPER_DAPP_NETWORKMANAGER_H
