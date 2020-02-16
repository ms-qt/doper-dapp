//
// Created by maohuawei on 2020/2/5.
//

#include "RoomListModel.h"


RoomListModel::RoomListModel()
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


RoomListModel::~RoomListModel()
{

}

void RoomListModel::refresh()
{
    setQuery("SELECT * FROM _room_list ");
}

QVariant RoomListModel::data(const QModelIndex &index, int role) const
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

QHash<int, QByteArray> RoomListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[_id] = "_id";
    return roles;
}

QString RoomListModel::getRoomType(QString roomId)
{
    qDebug() << "获取房间类型"<<roomId;
    QSqlQuery result;
    QString sql = "SELECT _room_type FROM _room_list WHERE _room_id = '" + roomId + "'";
    qDebug() << "sql : " << sql;
    if (result.exec(sql))
    {
        QString type;
        while (result.next())
        {
            type = result.value(0).toString();
        }
        return type;
    }
}


QString RoomListModel::getRoomName(QString roomId)
{
    qDebug() << "RoomListModel::getRoomName";
    QSqlQuery result;
    QString sql;
    QString roomType = getRoomType(roomId);
    qDebug() << "roomType : " << roomType;
    if (roomType == "_p2p")
    {
        sql = "SELECT _room_name FROM _room_p2p WHERE _room_id = '" + roomId + "'";
    }
    qDebug() << "sql : " << sql;
    if (result.exec(sql))
    {
        QString roomName;
        while (result.next())
        {
            roomName = result.value(0).toString();
        }
        return roomName;
    }
}

QString RoomListModel::getRoomAvatar(QString roomId)
{
    qDebug() << "RoomListModel::getRoomAvatar";
    QSqlQuery result;
    QString sql;
    QString roomType = getRoomType(roomId);
    qDebug() << "roomType : " << roomType;
    if (roomType == "_p2p")
    {
        sql = "SELECT _room_avatar FROM _room_p2p WHERE _room_id = '" + roomId + "'";
    }
    qDebug() << "sql : " << sql;
    if (result.exec(sql))
    {
        QString roomAvatar;
        while (result.next())
        {
            roomAvatar = result.value(0).toString();
        }
        return roomAvatar;
    }
}
