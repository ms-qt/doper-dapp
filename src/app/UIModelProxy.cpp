//
// Created by 毛华伟 on 2020/1/20.
//

#include "UIModelProxy.h"


UIModelProxy *UIModelProxy::instance = nullptr;


UIModelProxy::UIModelProxy()
{

}

UIModelProxy::~UIModelProxy()
{

}

UIModelProxy *UIModelProxy::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new UIModelProxy();
    }
    return instance;
}

void UIModelProxy::DeleteInstance()
{
    if (instance != nullptr)
    {
        delete instance;
    }
}