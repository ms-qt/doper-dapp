//
// Created by maohuawei on 2020/2/5.
//

#ifndef DOPER_DAPP_ROOMLISTMODEL_H
#define DOPER_DAPP_ROOMLISTMODEL_H


#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QVariant>
#include <QHash>


class RoomListModel : public QSqlQueryModel
{

Q_OBJECT
public:
    enum Roles
    {
        _id = Qt::UserRole + 1,//257
        _user_id,
        _room_id,
        _room_type
    };

public:

    RoomListModel();

    ~RoomListModel() ;

    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;


public slots:

    void refresh();

    QString getRoomName(QString roomId);

    QString getRoomType(QString roomId);

    QString getRoomAvatar(QString roomId);


private:

    const QString __TABLE_NAME__ = "_room_list";
    const QString __CREATE_TABLE__ = "CREATE TABLE IF NOT EXISTS _room_list\n"
                                     "(\n"
                                     "    _id      integer primary key autoincrement,\n"
                                     "    _user_id varchar(256),\n"
                                     "    _room_id varchar(256),\n"
                                     "    _room_type varchar (256)\n"
                                     ");";
};


#endif //DOPER_DAPP_ROOMLISTMODEL_H
