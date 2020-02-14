//
// Created by maohuawei on 2020/2/5.
//

#ifndef DOPER_DAPP_ROOMMENBERMODEL_H
#define DOPER_DAPP_ROOMMENBERMODEL_H


#include <QObject>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

class RoomMenberModel : public QSqlQueryModel
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

    RoomMenberModel();

    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;

public slots:

    void refresh();


private:

    const QString __TABLE_NAME__ = "";
    const QString __CREATE_TABLE__ = "";

};


#endif //DOPER_DAPP_ROOMMENBERMODEL_H
