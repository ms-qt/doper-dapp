//
// Created by 毛华伟 on 2020/1/16.
//

#include "TaskModel.h"


TaskModel::TaskModel()
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

TaskModel::~TaskModel()
{


}


void TaskModel::refresh()
{

    setQuery("select * from _task");

}


QVariant TaskModel::data(const QModelIndex &index, int role) const
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


QHash<int, QByteArray> TaskModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[_id] = "_id";
    roles[_task_id] = "_task_id";
    roles[_task_name] = "_task_name";
    roles[_task_desc] = "_task_desc";
    roles[_task_creator_id] = "_task_creator_id";
    roles[_task_executor_id] = "_task_executor_id";
    roles[_task_create_time] = "_task_create_time";
    roles[_task_start_time] = "_task_start_time";
    roles[_task_end_time] = "_task_end_time";
    roles[_task_remark] = "_task_remark";
    roles[_task_supervisor] = "_task_supervisor";
    roles[_task_priority] = "_task_priority";
    roles[_task_status] = "_task_status";

    return roles;
}


QString TaskModel::getTaskName(QString taskId)
{
    qDebug() << " 获取任务名称  : " << taskId;

    QSqlQuery result;

    QString sql = "SELECT _task_name FROM _task WHERE _task_id = '" + taskId + "' ";

    qDebug() << " sql  : " << sql;

    if (result.exec(sql))
    {
        qDebug() << "成功";
        QString taskName;
        while (result.next())
        {
            taskName = result.value(0).toString();
        }
        return  taskName;
    } else
    {
        qDebug() << " err : " << result.lastError().text();
        return "failure";
    }
}
