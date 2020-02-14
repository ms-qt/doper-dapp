//
// Created by 毛华伟 on 2020/1/16.
//

#ifndef DOPER_DAPP_TASKMODEL_H
#define DOPER_DAPP_TASKMODEL_H


#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

class TaskModel : public QSqlQueryModel
{

Q_OBJECT
public:
    enum Roles
    {
        _id = Qt::UserRole + 1,//257
        _task_id,
        _task_name,
        _task_desc,
        _task_creator_id,
        _task_executor_id,
        _task_create_time,
        _task_start_time,
        _task_end_time,
        _task_remark,
        _task_supervisor,
        _task_priority ,
        _task_status
    };

public:
    TaskModel();

    ~TaskModel();


    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;


public slots:

    void refresh();

    QString getTaskName(QString taskId);



private:

    const QString __TABLE_NAME__ = "_task";
    const QString __CREATE_TABLE__ = "CREATE TABLE IF NOT EXISTS _task\n"
                                     "(\n"
                                     "    _id               integer primary key autoincrement,\n"
                                     "    _task_id          varchar(256),\n"
                                     "    _task_name        varchar(256),\n"
                                     "    _task_desc        text,\n"
                                     "    _task_creator_id  varchar(256),\n"
                                     "    _task_executor_id varchar(256),\n"
                                     "    _task_create_time integer,\n"
                                     "    _task_start_time  integer,\n"
                                     "    _task_end_time    integer,\n"
                                     "    _task_remark      text,\n"
                                     "    _task_supervisor  varchar(256),\n"
                                     "    _task_priority    varchar(256),\n"
                                     "    _task_status      varchar(256)\n"
                                     ");";


};


#endif //DOPER_DAPP_TASKMODEL_H
