//
// Created by 毛华伟 on 2020/1/17.
// 凭证数据库
//
#pragma execution_character_set("utf-8")
#ifndef DOPER_DAPP_CERTIFICATEDB_H
#define DOPER_DAPP_CERTIFICATEDB_H

#include <QString>
#include <QSqlDatabase>
#include <QDebug>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>

#include <QDateTime>
#include "CertificateBean.h"

class CertificateDB : public QSqlQueryModel
{
Q_OBJECT
public:

    enum Roles
    {
        _id = Qt::UserRole + 1,//257
        _user_id,
        _username,
        _password,
        _access_token,
        _refresh_token,
        _login_type,
        _save_password,
        _auto_login,
        _time

    };

public:

    CertificateDB();

    CertificateBean *queryLaster();

    Q_INVOKABLE
    bool usernameCheckUserExists(QString username);

    Q_INVOKABLE
    bool userIdCheckUserExists(QString userid);

    void insert(CertificateBean *certificateBean);


public:

    const QString __TABLE_NAME__ = "_certificate";
    const QString __CREATE_TABLE__ = "CREATE TABLE IF NOT EXISTS _certificate\n"
                                     "(\n"
                                     "    _id            integer primary key autoincrement,\n"
                                     "    _user_id       varchar(256),\n"
                                     "    _username      varchar(256),\n"
                                     "    _password      varchar(256),\n"
                                     "    _access_token  varchar(256),\n"
                                     "    _refresh_token varchar(256),\n"
                                     "    _login_type    varchar(256),\n"
                                     "    _save_password boolean,\n"
                                     "    _auto_login    boolean,\n"
                                     "    _time          integer\n"
                                     ");";


};


#endif //DOPER_DAPP_CERTIFICATEDB_H
