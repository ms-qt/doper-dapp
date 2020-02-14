//
// Created by 毛华伟 on 2020/1/17.
// 组织部门成员表达
//

#ifndef DOPER_DAPP_ORGANIZATIONMEMBERMODEL_H
#define DOPER_DAPP_ORGANIZATIONMEMBERMODEL_H

#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

class OrganizationMemberModel : public QSqlQueryModel
{

Q_OBJECT
public:
    enum Roles
    {
        _id = Qt::UserRole + 1,//257
        _department_id,
        _department_name,
        _department_number_count,
        _department_desc
    };

public:
    OrganizationMemberModel();

    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;

public slots:

    void refresh();


private:

    const QString __TABLE_NAME__ = "_organization_member";
    const QString __CREATE_TABLE__ = "CREATE TABLE IF NOT EXISTS _organization_member\n"
                                     "(\n"
                                     "    _id              integer primary key autoincrement,\n"
                                     "    _department_id   varchar(255),\n"
                                     "    _department_name varchar(255),\n"
                                     "    _user_id         varchar(255)\n"
                                     ");";
};


#endif //DOPER_DAPP_ORGANIZATIONMEMBERMODEL_H
