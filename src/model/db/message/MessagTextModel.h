//
// Created by maohuawei on 2020/2/5.
//
#pragma execution_character_set("utf-8")
#ifndef DOPER_DAPP_MESSAGTEXTMODEL_H
#define DOPER_DAPP_MESSAGTEXTMODEL_H

#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QVariant>
#include <QHash>

class MessagTextModel : public QSqlQueryModel
{
Q_OBJECT
public:
    enum Roles
    {

        _id = Qt::UserRole + 1,//257
        _room_id,
        _message_id,
        _event_id,
        _sender_id,
        _time,
        _text_content,
        _message_sender_time,
        _message_receive_time,
        _is_me,
        _is_read
    };


public:
    MessagTextModel();

    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;

public slots:

    void refresh();


private:

    const QString __TABLE_NAME__ = "_message_text";
    const QString __CREATE_TABLE__ = "CREATE TABLE IF NOT EXISTS _message_text\n"
                                     "(\n"
                                     "    _id                   integer primary key autoincrement,\n"
                                     "    _room_id              varchar(255),\n"
                                     "    _message_id           varchar(255),\n"
                                     "    _event_id             varchar(255),\n"
                                     "    _sender_id            varchar(255),\n"
                                     "    _time                 bigint,\n"
                                     "    _text_content         text,\n"
                                     "    _message_sender_time  bigint,\n"
                                     "    _message_receive_time bigint,\n"
                                     "    _is_me                boolean,\n"
                                     "    _is_read              boolean\n"
                                     ");";

};


#endif //DOPER_DAPP_MESSAGTEXTMODEL_H
