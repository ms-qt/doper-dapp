//
// Created by maohuawei on 2020/2/5.
//

#ifndef DOPER_DAPP_MESSAGELISTMODEL_H
#define DOPER_DAPP_MESSAGELISTMODEL_H


#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

#include "src/model/db/message/MessageBeanText.h"

class MessageListModel : public QSqlQueryModel
{

Q_OBJECT
public:
    enum Roles
    {
        _id = Qt::UserRole + 1,//257
        _room_id,
        _room_type,
        _message_id,
        _message_type,
        _event_id,
        _time
    };

public:
    MessageListModel();
    ~MessageListModel();

    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;

public slots:

    void refresh();

    void enterRoom(QString roomId);


    QString getRoomLasterMessageType(QString roomId);

    QString getRoomLasterMessage(QString roomId);

    MessageBeanText* getLasterMessageText(QString roomId);


private:

    const QString __TABLE_NAME__ = "_message_list";
    const QString __CREATE_TABLE__ = "CREATE TABLE IF NOT EXISTS _message_list\n"
                                     "(\n"
                                     "    _id           integer primary key autoincrement,\n"
                                     "    _room_id      varchar(256),\n"
                                     "    _room_type    varchar(256),\n"
                                     "    _message_id   varchar(256),\n"
                                     "    _message_type varchar(256),\n"
                                     "    _event_id     varchar(256),\n"
                                     "    _time         bigint\n"
                                     ");";

};


#endif //DOPER_DAPP_MESSAGELISTMODEL_H
