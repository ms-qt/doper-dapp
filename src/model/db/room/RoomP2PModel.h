//
// Created by 毛华伟 on 2020/1/17.
// 两人对话
//
#pragma execution_character_set("utf-8")
#ifndef DOPER_DAPP_ROOMP2PMODEL_H
#define DOPER_DAPP_ROOMP2PMODEL_H

#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QVariant>
#include <QHash>

class RoomP2PModel : public QSqlQueryModel
{

Q_OBJECT
public:
    enum Roles
    {
        _id = Qt::UserRole + 1,//257
        _room_id,
        _room_name,
        _room_avatar,
        _room_version,
    };

public:

    RoomP2PModel();

    ~RoomP2PModel();

    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;

public slots:

    void refresh();

private:
    const QString __TABLE_NAME__ = "_room_p2p";

    const QString __CREATE_TABLE__ = "CREATE TABLE IF NOT EXISTS _room_p2p\n"
                                     "(\n"
                                     "    _id           integer primary key autoincrement,\n"
                                     "    _room_id      varchar(256),\n"
                                     "    _room_name    varchar(256),\n"
                                     "    _room_avatar  varchar(1024),\n"
                                     "    _room_version integer\n"
                                     ");";
};


#endif //DOPER_DAPP_ROOMP2PMODEL_H
