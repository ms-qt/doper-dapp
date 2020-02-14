//
// Created by 毛华伟 on 2020/1/19.
//

#include "ThreadTool.h"


ThreadTool *ThreadTool::instance = nullptr;


rxcpp::observe_on_one_worker ThreadTool::main_thread = rxcpp::observe_on_one_worker(rxcpp::schedulers::scheduler());

ThreadTool::ThreadTool()
{

}

ThreadTool::~ThreadTool()
{

}

ThreadTool *ThreadTool::getInstance()
{
    if (instance == nullptr)
    {
        instance = new ThreadTool();
    }
    return instance;
}