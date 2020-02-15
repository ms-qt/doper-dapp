//
// Created by maohuawei on 2020/2/5.
//

#ifndef DOPER_DAPP_TASKLISTMODEL_H
#define DOPER_DAPP_TASKLISTMODEL_H


#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>


class TaskListModel : public QSqlQueryModel
{

Q_OBJECT
public:
    enum Roles
    {
        _id = Qt::UserRole + 1,//257
        _user_id,
        _task_id
    };

public:
    TaskListModel();

    ~TaskListModel();


    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;


public slots:

    void refresh();

    void enterTask(QString taskId);


private:

    const QString __TABLE_NAME__ = "_task_list";
    const QString __CREATE_TABLE__ = "CREATE TABLE IF NOT EXISTS _task_list\n"
                                     "(\n"
                                     "    _id               integer primary key autoincrement,\n"
                                     "    _user_id          varchar(256),\n"
                                     "    _task_id          varchar(256)\n"
                                     ");";

};


#endif //DOPER_DAPP_TASKLISTMODEL_H
