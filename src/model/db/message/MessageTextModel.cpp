//
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
    QString sql = "SELECT _text_content FROM _message_text WHERE _message_id = '"+messageId+"'";
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
