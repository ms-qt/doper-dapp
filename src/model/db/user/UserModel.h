//
// Created by 毛华伟 on 2020/1/17.
//
#pragma execution_character_set("utf-8")
#ifndef DOPER_DAPP_USERMODEL_H
#define DOPER_DAPP_USERMODEL_H

#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QVariant>
#include <QHash>


#include "src/model/bean/user/UserBean.h"

class UserModel : public QSqlQueryModel
{
Q_OBJECT
public:
    enum Roles
    {
        _id = Qt::UserRole + 1,//257
        _user_id,
        _name,
        _age,
        _sex,
        _department,
        _job_title,
        _avatar,
        _signature,
        _phonenumber,
        _email,
        _qq,
        _introduction,
        _company
    };

    UserModel();

    ~UserModel();

    void refresh();

    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;


public slots:

    QString getName(QString userId);

    QString getAvatar(QString userId);

    QString getSignature(QString userId);

    void setSignature(QString userId,QString text);
    
    void sendMessage(QString userId);

    UserBean* getUserByUserId(QString userId);



private:

    const QString __TABLE_NAME__ = "_user";
    const QString __CREATE_TABLE__ = "CREATE TABLE IF NOT EXISTS _user\n"
                                     "(\n"
                                     "    _id           integer primary key autoincrement,\n"
                                     "    _user_id      varchar(256),\n"
                                     "    _name         varchar(256),\n"
                                     "    _age          integer,\n"
                                     "    _sex          integer,\n"
                                     "    _department   varchar(256),\n"
                                     "    _job_title    varchar(256),\n"
                                     "    _avatar       varchar(1024),\n"
                                     "    _signature    varchar(1024),\n"
                                     "    _phonenumber  varchar(256),\n"
                                     "    _email        varchar(256),\n"
                                     "    _qq           varchar(256),\n"
                                     "    _introduction text,\n"
                                     "    _company      varchar(256)\n"
                                     ");";
};


#endif //DOPER_DAPP_USERMODEL_H
