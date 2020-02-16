//
// Created by 毛华伟 on 2020/1/17.
//

#include "CertificateDB.h"

CertificateDB::CertificateDB()
{
    if (QSqlDatabase::database().tables().contains(__TABLE_NAME__))
    {
        qDebug() << __TABLE_NAME__ << " 连接成功";
        return;
    } else
    {
        qDebug() << __TABLE_NAME__ << " 连接失败 ";
        qDebug() << " 创建消息表 ";
        QSqlQuery sqlQuery;
        if (sqlQuery.exec(__CREATE_TABLE__))
        {
            qDebug() << __TABLE_NAME__ << "  创建成功";
        } else
        {
            qDebug() << __TABLE_NAME__ << "  创建失败" << sqlQuery.lastError().text();
        }
    }
}


// 查询最后一条数据
CertificateBean *CertificateDB::queryLaster()
{
    QString sql = "select * from _certificate order by _time desc  limit 1";
    QSqlQuery result;
    result.exec(sql);

//    _id
//    _user_id
//    _username
//    _password
//    _access_token
//    _refresh_token
//    _login_type
//    _save_password
//    _auto_login
//    _time


    CertificateBean *certificateBean = new CertificateBean();
    while (result.next())
    {
        int id = result.value(0).toInt();
        QString userid = result.value(1).toString();
        QString username = result.value(2).toString();
        QString password = result.value(3).toString();
        QString access_token = result.value(4).toString();
        QString refresh_token = result.value(53).toString();
        QString login_type = result.value(6).toString();
        bool save_password = result.value(7).toBool();
        bool auto_login = result.value(8).toBool();
        int time = result.value(9).toInt();

        certificateBean->_id = (id);
        certificateBean->_user_id = (userid);
        certificateBean->_username = (username);
        certificateBean->_password = (password);
        certificateBean->_access_token = (access_token);
        certificateBean->_refresh_token = (refresh_token);
        certificateBean->_auto_login = (auto_login);
        certificateBean->_save_password = (save_password);
        certificateBean->_time = (time);
    }
    return certificateBean;

}


bool CertificateDB::usernameCheckUserExists(QString username)
{
    qDebug() << "CertificateDB::usernameCheckUserExists : " << username;

    QSqlQuery result;
    QString sql = "select _username from _certificate";
    result.exec(sql);
    QList<QString> list;
    while (result.next())
    {
        QString uname = result.value(0).toString();
        list.append(uname);
    }
    for (QString it: list)
    {
        if (it == username)
        {
            return true;
        }
    }
    return false;
}

bool CertificateDB::userIdCheckUserExists(QString userid)
{
    QSqlQuery result;
    QString sql = "select _user_id from _certificate";
    result.exec(sql);
    QList<QString> list;
    while (result.next())
    {
        QString uname = result.value(0).toString();
        list.append(uname);
    }
    for (QString it: list)
    {
        if (it == userid)
        {
            return true;
        }
    }
    return false;
}


void CertificateDB::insert(CertificateBean *certificateBean)
{
    QString userId = certificateBean->userid();
    QString username = certificateBean->username();
    QString password = certificateBean->password();
    QString accessToken = certificateBean->access_token();
    QString loginType = certificateBean->login_type();
    QString refreshToken = certificateBean->refresh_token();
    bool autoLogin = certificateBean->auto_login();
    bool savePassword = certificateBean->save_password();


    QString sql;

    if (usernameCheckUserExists(username))
    {
        // 存在更新


        sql = "UPDATE _certificate SET "
              "                        _user_id='" + userId + "', "
                                                              "                        _username='" + username + "', "
                                                                                                                 "                        _password='" +
              password + "', "
                         "                        _access_token='" + accessToken + "', "
                                                                                   "                        _refresh_token='" +
              refreshToken + "', "
                             "                        _login_type='" + loginType + "', "
                                                                                   "                        _save_password=" +
              QString::number(savePassword) + ", "
                                              "                        _auto_login=" + QString::number(autoLogin) + ", "
                                                                                                                    "                        _time=" +
              QString::number(QDateTime::currentDateTime().toTime_t()) + " "
                                                                         "                        WHERE _username = '" +
              username + "'";

    } else
    {
        // 插入
        sql = "INSERT INTO _certificate ("
              "                          _user_id,"
              "                          _username,"
              "                          _password,"
              "                          _access_token,"
              "                          _refresh_token,"
              "                          _login_type,"
              "                          _save_password,"
              "                          _auto_login,"
              "                          _time"
              "                          )"
              "VALUES ("
              "'" + userId + "',"
                             "'" + username + "',"
                                              "'" + password + "',"
                                                               "'" + accessToken + "',"
                                                                                   "'" + refreshToken + "',"
                                                                                                        "'" +
              loginType + "',"
                          "" + QString::number(savePassword) + ","
                                                               "" + QString::number(autoLogin) + ","
                                                                                                 "" +
              QString::number(QDateTime::currentDateTime().toTime_t()) + ")";


    }


    qDebug() << " sql :  " << sql;

    QSqlQuery result;


    result.exec(sql);

    qDebug() << result.lastError().text();

}
