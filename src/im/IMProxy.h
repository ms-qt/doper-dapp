//
// Created by 毛华伟 on 2020/1/8.
//

#ifndef APP_IMPROXY_H
#define APP_IMPROXY_H

#include <QObject>
#include <QString>
#include <QDebug>
#include "src/app/UIModelProxy.h"
#include <folly/json.h>

#include "src/im/LoginCallBack.h"
class IMProxy : public QObject
{
Q_OBJECT
public:

    IMProxy();

    void login(QString username, QString password, bool savePassword, bool autoLogin, LoginCallBack *callBack);

private:


};


#endif //APP_IMPROXY_H
