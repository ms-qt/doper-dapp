//
// Created by 毛华伟 on 2020/1/19.
//

#ifndef DOPER_DAPP_IMMODEL_H
#define DOPER_DAPP_IMMODEL_H

#include <QObject>
#include <QDebug>
#include "IMProxy.h"

class IMModel : public QObject
{

Q_OBJECT
public:
    IMModel();

    IMProxy *imProxy = nullptr;
    
    Q_INVOKABLE
    void login(QString username, QString password, bool savePassword, bool autoLogin);
};


#endif //DOPER_DAPP_IMMODEL_H
