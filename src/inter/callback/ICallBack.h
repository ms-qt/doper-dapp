//
// Created by 毛华伟 on 2020/1/19.
//

#ifndef DOPER_DAPP_ICALLBACK_H
#define DOPER_DAPP_ICALLBACK_H


#include <iostream>

// 接口回调接口
class ICallBack
{
public:
    virtual void onSuccess(std::string res) = 0;

    virtual void onFailure(std::string res) = 0;
};


#endif //DOPER_DAPP_ICALLBACK_H
