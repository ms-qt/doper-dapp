//
// Created by maohuawei on 2020/2/5.
//

#include "TaskListModel.h"


TaskListModel::TaskListModel()
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


TaskListModel::~TaskListModel()
{


}

void TaskListModel::refresh()
{
    setQuery("select * from _task_list");
}

QVariant TaskListModel::data(const QModelIndex &index, int role) const
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

QHash<int, QByteArray> TaskListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[_id] = "_id";
    roles[_user_id] = "_user_id";
    roles[_task_id] = "_task_id";
    return roles;
}


void TaskListModel::enterTask(QString taskId)
{
    qDebug() << "enterRoom " + taskId;

    emit UIModelProxy::GetInstance()->enterTask(taskId);

}