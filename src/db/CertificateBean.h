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
                       id
                       READ
                       getId
                       CONSTANT
    )
    Q_PROPERTY(QString
                       user_id
                       READ
                       getUserId
                       CONSTANT
    )
    Q_PROPERTY(QString
                       username
                       READ
                       getUsername
                       CONSTANT
    )
    Q_PROPERTY(QString
                       password
                       READ
                       getPassword
                       CONSTANT
    )

    Q_PROPERTY(QString
                       access_token
                       READ
                       getAccessToken
                       CONSTANT
    )


    Q_PROPERTY(QString
                       refresh_token
                       READ
                       getRefreshToken
                       CONSTANT
    )


    Q_PROPERTY(QString
                       login_type
                       READ
                       getLoginType
                       CONSTANT
    )


    Q_PROPERTY(bool
                       save_password
                       READ
                       isSavePassword
                       CONSTANT
    )


    Q_PROPERTY(bool
                       auto_login
                       READ
                       isAutoLogin
                       CONSTANT
    )


    Q_PROPERTY(int
                       time
                       READ
                       getTime
                       CONSTANT
    )


public:
    CertificateBean()
    {};

    ~CertificateBean()
    {};

private:

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
    int getId() const
    {
        return _id;
    }

    void setId(int id)
    {
        _id = id;
    }

    const QString &getUserId() const
    {
        return _user_id;
    }

    void setUserId(const QString &userId)
    {
        _user_id = userId;
    }

    const QString &getUsername() const
    {
        return _username;
    }

    void setUsername(const QString &username)
    {
        _username = username;
    }

    const QString &getPassword() const
    {
        return _password;
    }

    void setPassword(const QString &password)
    {
        _password = password;
    }

    const QString &getAccessToken() const
    {
        return _access_token;
    }

    void setAccessToken(const QString &accessToken)
    {
        _access_token = accessToken;
    }

    const QString &getRefreshToken() const
    {
        return _refresh_token;
    }

    void setRefreshToken(const QString &refreshToken)
    {
        _refresh_token = refreshToken;
    }

    const QString &getLoginType() const
    {
        return _login_type;
    }

    void setLoginType(const QString &loginType)
    {
        _login_type = loginType;
    }

    bool isSavePassword() const
    {
        return _save_password;
    }

    void setSavePassword(bool savePassword)
    {
        _save_password = savePassword;
    }

    bool isAutoLogin() const
    {
        return _auto_login;
    }

    void setAutoLogin(bool autoLogin)
    {
        _auto_login = autoLogin;
    }

    int getTime() const
    {
        return _time;
    }

    void setTime(int time)
    {
        _time = time;
    }

public:

};


#endif //DOPER_DAPP_CERTIFICATEBEAN_H
