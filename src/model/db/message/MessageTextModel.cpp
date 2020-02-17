﻿//
// Created by maohuawei on 2020/2/5.
//

#include "MessageTextModel.h"

MessageTextModel::MessageTextModel()
{
    if (QSqlDatabase::database().tables().contains(__TABLE_NAME__))
    {
        qDebug() << __TABLE_NAME__ << " 连接成功";
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
    refresh();
}

void MessageTextModel::refresh()
{
    setQuery("SELECT * from _message_text ORDER BY _time DESC");
}

QVariant MessageTextModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlQueryModel::data(index, role);
    if (role < Qt::UserRole)
    {
        value = QSqlQueryModel::data(index, role);
    } else
    {
        int columnIdx = role - Qt::UserRole - 1;
        QModelIndex modelIndex = this->index(index.row(), columnIdx);
        value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
    }
    return value;
}

QHash<int, QByteArray> MessageTextModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[_id] = "_id";
    roles[_room_id] = "_room_id";
    roles[_message_id] = "_message_id";
    roles[_event_id] = "_event_id";
    roles[_sender_id] = "_sender_id";
    roles[_time] = "_time";
    roles[_text_content] = "_text_content";
    roles[_message_sender_time] = "_message_sender_time";
    roles[_message_receive_time] = "_message_receive_time";
    roles[_is_me] = "_is_me";
    roles[_is_read] = "_is_read";
    return roles;
}


QString MessageTextModel::textContentByMessageId(QString messageId)
{
    QSqlQuery result;
    QString sql = "SELECT _text_content FROM _message_text WHERE _message_id = '" + messageId + "'";
    if (result.exec(sql))
    {
        QString textContent;
        while (result.next())
        {
            textContent = result.value(0).toString();
        }
        return textContent;
    }
}

MessageBeanText *MessageTextModel::messageByMessageId(QString message_id)
{
    QSqlQuery result;
    QString sql = "SELECT * FROM _message_text WHERE _message_id = '" + message_id + "' ORDER BY _time DESC LIMIT 1";
    if (result.exec(sql))
    {
        MessageBeanText *messageBeanText = new MessageBeanText();
        while (result.next())
        {
            int _id = result.value(0).toInt();
            QString _room_id = result.value(1).toString();
            QString _message_id = result.value(2).toString();
            QString _event_id = result.value(3).toString();
            QString _sender_id = result.value(4).toString();
            qint64 _time = result.value(5).toLongLong() / 1000;
            QString _text_content = result.value(6).toString();
            qint64 _message_sender_time = result.value(7).toLongLong();
            qint64 _message_receive_time = result.value(8).toLongLong();
            bool _is_me = result.value(9).toBool();
            bool _is_read = result.value(10).toBool();

            messageBeanText->_id = (_id);
            messageBeanText->_room_id = (_room_id);
            messageBeanText->_message_id = (_message_id);
            messageBeanText->_event_id = (_event_id);
            messageBeanText->_sender_id = (_sender_id);
            messageBeanText->_time = (_time);
            messageBeanText->_text_content = (_text_content);
            messageBeanText->_message_sender_time = (_message_sender_time);
            messageBeanText->_message_receive_time = (_message_receive_time);
            messageBeanText->_is_me = (_is_me);
            messageBeanText->_is_read = (_is_read);
        }
        return messageBeanText;
    }
}