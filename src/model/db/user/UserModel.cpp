//
// Created by 毛华伟 on 2020/1/17.
//

#include "UserModel.h"

UserModel::UserModel()
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

UserModel::~UserModel()
{
}

QHash<int, QByteArray> UserModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[_id] = "_id";
    roles[_user_id] = "_user_id";
    roles[_name] = "_name";
    roles[_age] = "_age";
    roles[_sex] = "_sex";
    roles[_department] = "_department";
    roles[_job_title] = "_job_title";
    roles[_avatar] = "_avatar";
    roles[_signature] = "_signature";
    roles[_phonenumber] = "_phonenumber";
    roles[_email] = "_email";
    roles[_qq] = "_qq";
    roles[_introduction] = "_introduction";
    roles[_company] = "_company";
    return roles;
}

QVariant UserModel::data(const QModelIndex &index, int role) const
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


void UserModel::refresh()
{
    setQuery("SELECT * FROM _user");
}

QString UserModel::getName(QString userId)
{
    QSqlQuery result;
    QString sql = "SELECT _name FROM _user WHERE _user_id = '" + userId + "'";
    if (result.exec(sql))
    {
        QString name;
        while (result.next())
        {
            name = result.value(0).toString();
        }
        return name;
    }
}

QString UserModel::getAvatar(QString userId)
{
    qDebug() << "UserModel::getAvatar";
    QSqlQuery result;
    QString sql = "SELECT _avatar FROM _user WHERE _user_id = '" + userId + "'";
    if (result.exec(sql))
    {
        QString avatar;
        while (result.next())
        {
            avatar = result.value(0).toString();
        }
        qDebug() << "UserModel::getAvatar" << avatar;
        return avatar;
    }
}

QString UserModel::getSignature(QString userId)
{
    qDebug() << "UserModel::getSignature";
    QSqlQuery result;
    QString sql = "SELECT _signature FROM _user WHERE _user_id = '" + userId + "'";
    qDebug() << "UserModel::getSignature sql " << sql;
    if (result.exec(sql))
    {
        QString signature;
        while (result.next())
        {
            signature = result.value(0).toString();
        }
        qDebug() << "UserModel::getSignature" << signature;
        return signature;
    }
}

void UserModel::setSignature(QString userId, QString text)
{
    qDebug() << "UserModel::setSignature";
    QSqlQuery result;
    QString sql = "UPDATE _user SET _signature = '" + text + "' WHERE _user_id = '" + userId + "'";
    qDebug() << "UserModel::setSignature sql " << sql;
    if (result.exec(sql))
    {
    }
}

void UserModel::sendMessage(QString userId)
{

}

UserBean *UserModel::getUserByUserId(QString userId)
{
    qDebug()<<"UserBean *UserModel::getUserByUserId(QString userId)"<<userId;
    QSqlQuery result;
    QString sql = "SELECT * FROM _user WHERE _user_id = '" + userId + "'";
    if (result.exec(sql))
    {
        UserBean *userBean = new UserBean();
        while (result.next())
        {
            int _id = result.value(0).toInt();
            QString _user_id = result.value(1).toString();
            QString _name = result.value(2).toString();
            int _age = result.value(3).toInt();
            bool _sex = result.value(4).toBool();
            QString _department = result.value(5).toString();
            QString _job_title = result.value(6).toString();
            QString _avatar = result.value(7).toString();
            QString _signature = result.value(8).toString();
            QString _phonenumber = result.value(9).toString();
            QString _email = result.value(10).toString();
            QString _qq = result.value(11).toString();
            QString _introduction = result.value(12).toString();
            QString _company = result.value(13).toString();

            userBean->_id = _id;
            userBean->_user_id = _user_id;
            userBean->_name = _name;
            userBean->_age = _age;
            userBean->_sex = _sex;
            userBean->_department = _department;
            userBean->_job_title = _job_title;
            userBean->_avatar = _avatar;
            userBean->_signature = _signature;
            userBean->_phonenumber = _phonenumber;
            userBean->_email = _email;
            userBean->_qq = _qq;
            userBean->_introduction = _introduction;
            userBean->_company = _company;
        }
        return userBean;
    }
}
