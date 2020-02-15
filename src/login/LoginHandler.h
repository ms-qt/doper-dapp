//
// Created by 毛华伟 on 2020/2/15.
//

#ifndef APP_LOGINHANDLER_H
#define APP_LOGINHANDLER_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include "src/local/db/CertificateBean.h"
#include "src/local/db/CertificateDB.h"

#include "src/tool/ThreadTool.h"

class LoginHandler : public QObject
{
Q_OBJECT
public:
    LoginHandler();

    ~LoginHandler();

public slots:

    void login(QString username, QString password, bool savePassword, bool autoLogin);

signals:

    void loginSuccess();

    void loginFailure();


};


#endif //APP_LOGINHANDLER_H
