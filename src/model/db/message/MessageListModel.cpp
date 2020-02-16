//
// Created by maohuawei on 2020/2/5.
//

#include "MessageListModel.h"


MessageListModel::MessageListModel()
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


MessageListModel::~MessageListModel()
{

};


void MessageListModel::refresh()
{
    setQuery("SELECT * FROM _message_list");
}

QVariant MessageListModel::data(const QModelIndex &index, int role) const
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

QHash<int, QByteArray> MessageListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[_id] = "_id";
    roles[_room_id] = "_room_id";
    roles[_room_type] = "_room_type";
    roles[_message_id] = "_message_id";
    roles[_message_type] = "_message_type";
    roles[_event_id] = "_event_id";
    roles[_time] = "_time";
    return roles;
}


void MessageListModel::enterRoom(QString roomId)
{

}

QString MessageListModel::getRoomLasterMessageType(QString roomId)
{
    qDebug() << " 获取房间最后一条信息类型" << roomId;
    QString sql =
            "SELECT _message_type FROM  _message_list WHERE _room_id = '" + roomId + "' ORDER BY _time DESC LIMIT 1";
    qDebug() << "sql : " << sql;

    QSqlQuery result;

    if (result.exec(sql))
    {

        QString messageType;
        while (result.next())
        {
            messageType = result.value(0).toString();
        }
        return messageType;
    }
}


QString MessageListModel::getRoomLasterMessage(QString roomId)
{

    qDebug() << " 获取房间最后一条信息" << roomId;

    QString messageType = getRoomLasterMessageType(roomId);

    QString sql;

    if (messageType == "_text")
    {
        sql = "SELECT _text_content FROM _message_text WHERE _room_id = '" + roomId + "' ORDER BY _time DESC LIMIT 1";
    }


    qDebug() << "sql : " << sql;

    QSqlQuery result;

    if (result.exec(sql))
    {
        QString message;
        while (result.next())
        {
            message = result.value(0).toString();
        }
        return message;
    }
}


MessageBeanText *MessageListModel::getLasterMessageText(QString roomId)
{
    QString sql =
            "SELECT * FROM _message_text WHERE _room_id = '" + roomId + "' ORDER BY _time DESC LIMIT 1";

    QSqlQuery result;


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

            messageBeanText->setMessageId(_message_id);
            messageBeanText->setTextContent(_text_content);
            messageBeanText->setTime(_time);
        }
        return messageBeanText;
    }
}


void MessageListModel::filterByRoomId(QString roomId)
{
    setQuery("select * from _message_list where _room_id = '" + roomId + "'");
}