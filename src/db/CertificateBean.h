//
// Created by 毛华伟 on 2020/1/17.
// 凭证实体类
//

#ifndef DOPER_DAPP_CERTIFICATEBEAN_H
#define DOPER_DAPP_CERTIFICATEBEAN_H


#include <QObject>
#include <QString>

class CertificateBean : public QObject
{

Q_OBJECT
    Q_PROPERTY(int
                       _id
                       READ
                       id
                       CONSTANT
    )
    Q_PROPERTY(QString
                       _user_id
                       READ
                       userid
                       CONSTANT
    )
    Q_PROPERTY(QString
                       _username
                       READ
                       username
                       CONSTANT
    )
    Q_PROPERTY(QString
                       _password
                       READ
                       password
                       CONSTANT
    )

    Q_PROPERTY(QString
                       _access_token
                       READ
                       access_token
                       CONSTANT
    )


    Q_PROPERTY(QString
                       _refresh_token
                       READ
                       refresh_token
                       CONSTANT
    )


    Q_PROPERTY(QString
                       _login_type
                       READ
                       login_type
                       CONSTANT
    )


    Q_PROPERTY(bool
                       _save_password
                       READ
                       save_password
                       CONSTANT
    )


    Q_PROPERTY(bool
                       _auto_login
                       READ
                       auto_login
                       CONSTANT
    )


    Q_PROPERTY(int
                       _time
                       READ
                       time
                       CONSTANT
    )


public:
    CertificateBean()
    {};

    ~CertificateBean()
    {};

public:
    int _id;
    QString _user_id;
    QString _username;
    QString _password;
    QString _access_token;
    QString _refresh_token;
    QString _login_type;
    bool _save_password;
    bool _auto_login;
    int _time;

public:
    int id() const
    {
        return _id;
    }

    const QString &userid() const
    {
        return _user_id;
    }

    const QString &username() const
    {
        return _username;
    }

    const QString &password() const
    {
        return _password;
    }

    const QString &access_token() const
    {
        return _access_token;
    }

    const QString &refresh_token() const
    {
        return _refresh_token;
    }

    const QString &login_type() const
    {
        return _login_type;
    }

    bool save_password() const
    {
        return _save_password;
    }

    bool auto_login() const
    {
        return _auto_login;
    }

    int time() const
    {
        return _time;
    }
};


#endif //DOPER_DAPP_CERTIFICATEBEAN_H
