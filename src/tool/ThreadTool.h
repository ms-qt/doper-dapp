//
// Created by 毛华伟 on 2020/1/19.
// 线程工具
//

#ifndef DOPER_DAPP_THREADTOOL_H
#define DOPER_DAPP_THREADTOOL_H


#include <rxcpp/rx.hpp>
#include <rxcpp/schedulers/rx-sameworker.hpp>
#include <rxcpp/rx-scheduler.hpp>


class ThreadTool
{
public:
    static ThreadTool *getInstance();

public:
    // 操作ui的线程
    static rxcpp::observe_on_one_worker main_thread;
private:
    ThreadTool();

    ~ThreadTool();

private:
    static ThreadTool *instance;

};


#endif //DOPER_DAPP_THREADTOOL_H
