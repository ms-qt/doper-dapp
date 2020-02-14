//
// Created by 毛华伟 on 2020/1/17.
// 任务消息
//

#ifndef DOPER_DAPP_ROOMTASKMODEL_H
#define DOPER_DAPP_ROOMTASKMODEL_H

#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>


class RoomTaskModel : public QSqlQueryModel
{

Q_OBJECT
public:
    enum Roles
    {
        _id = Qt::UserRole + 1,//257
    };

public:

    RoomTaskModel();

    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;

public slots:

    void refresh();


private:

    const QString __TABLE_NAME__ = "";
    const QString __CREATE_TABLE__ = "";


};


#endif //DOPER_DAPP_ROOMTASKMODEL_H
