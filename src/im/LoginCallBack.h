//
// Created by 毛华伟 on 2020/1/19.
//

#ifndef DOPER_DAPP_LOGINCALLBACK_H
#define DOPER_DAPP_LOGINCALLBACK_H


#include "src/inter/callback/ICallBack.h"
#include <folly/json.h>
#include <folly/dynamic.h>
#include "src/db/CertificateDB.h"
#include "src/db/CertificateBean.h"
#include <QObject>
#include <QDebug>
#include "src/app/UIModelProxy.h"

class LoginCallBack : public ICallBack, QObject
{
public:
    LoginCallBack();

    ~LoginCallBack();

    void onSuccess(std::string res) override;

    void onFailure(std::string res) override;

signals:

    void loginSuccess();

};


#endif //DOPER_DAPP_LOGINCALLBACK_H
