#include "TaoJsonTreeModel.h"
#include "FileReadWrite.h"
#include <QJsonArray>

#include <QDebug>

namespace TaoCommon {

void TaoJsonTreeModel::loadFromJson(const QString& jsonPath, const QString& recursionKey)
{
    QJsonArray arr;
    if (!readJsonFile(jsonPath, arr)) {
        return;
    }
    m_recursionKey = recursionKey;
    beginResetModel();
    m_nodeList.clear();
    gen(0, arr);
    endResetModel();
    countChanged();
}

void TaoJsonTreeModel::loadFromJsonString(const QString & jsonValue, const QString & recursionKey)
{
	QJsonDocument doc = QJsonDocument::fromJson(jsonValue.toUtf8());
    QJsonArray arr = doc.array();
    m_recursionKey = recursionKey;
    beginResetModel();
    m_nodeList.clear();
    gen(0, arr);
    endResetModel();
    countChanged();
}
Q_INVOKABLE void TaoJsonTreeModel::loadFromName( const QString & recursionKey)
{

	QJsonArray main_json;

	QJsonArray arr_platform;
	QJsonObject object1_platform;
	object1_platform.insert("name",QStringLiteral("魏爱辉"));
	arr_platform.append(object1_platform);
	QJsonObject object2_platform;
	object2_platform.insert("name", QStringLiteral( "王志明"));
	arr_platform.append(object2_platform);
	QJsonObject object3_platform;
	object3_platform.insert("name", QStringLiteral("王晓波"));
	arr_platform.append(object3_platform);
	QJsonObject object4_platform;
	object4_platform.insert("name", QStringLiteral("李诗琦"));
	arr_platform.append(object4_platform);
	QJsonObject object5_platform;
	object5_platform.insert("name", QStringLiteral("李媛"));
	arr_platform.append(object5_platform);
	QJsonObject object6_platform;
	object6_platform.insert("name", QStringLiteral("石亚楠"));
	arr_platform.append(object6_platform);

	QJsonObject object_platform;
	object_platform.insert("name", QStringLiteral("平台管理"));
	object_platform.insert("subType", arr_platform);
	main_json.append(object_platform);


	QJsonArray arr_guanxi;
	QJsonObject object1_guanxi;
	object1_guanxi.insert("name", QStringLiteral("王静静"));
	arr_guanxi.append(object1_guanxi);
	QJsonObject object2_guanxi;
	object2_guanxi.insert("name", QStringLiteral("李洋萱"));
	arr_guanxi.append(object2_guanxi);
	QJsonObject object3_guanxi;
	object3_guanxi.insert("name", QStringLiteral("吴婧宇"));
	arr_guanxi.append(object3_guanxi);

	QJsonObject object_guanxi;
	object1_guanxi.insert("name", QStringLiteral("公共关系部"));
	object1_guanxi.insert("subType", arr_guanxi);
	main_json.append(object1_guanxi);

	QJsonArray arr_shuruiyanfa;
	QJsonObject object1_shuruiyanfa;
	object1_shuruiyanfa.insert("name", QStringLiteral("李卫宁"));
	arr_shuruiyanfa.append(object1_shuruiyanfa);
	QJsonObject object2_shuruiyanfa;
	object2_shuruiyanfa.insert("name", QStringLiteral("方士琦"));
	arr_shuruiyanfa.append(object2_shuruiyanfa);
	QJsonObject object3_shuruiyanfa;
	object3_shuruiyanfa.insert("name", QStringLiteral("汪浩琰"));
	arr_shuruiyanfa.append(object3_shuruiyanfa);
	QJsonObject object4_shuruiyanfa;
	object4_shuruiyanfa.insert("name", QStringLiteral("雷行京"));
	arr_shuruiyanfa.append(object4_shuruiyanfa);
	QJsonObject object5_shuruiyanfa;
	object5_shuruiyanfa.insert("name", QStringLiteral("罗大伟"));
	arr_shuruiyanfa.append(object5_shuruiyanfa);
	QJsonObject object6_shuruiyanfa;
	object6_shuruiyanfa.insert("name", QStringLiteral("张赛风"));
	arr_shuruiyanfa.append(object6_shuruiyanfa);
	QJsonObject object7_shuruiyanfa;
	object7_shuruiyanfa.insert("name", QStringLiteral("杨琦"));
	arr_shuruiyanfa.append(object7_shuruiyanfa);

	QJsonObject object_shuruiyanfa;
	object_shuruiyanfa.insert("name", QStringLiteral("产品研发部"));
	object_shuruiyanfa.insert("subType", arr_shuruiyanfa);


	QJsonArray arr_shuruishichang;
	QJsonObject object1_shuruishichang;
	object1_shuruishichang.insert("name", QStringLiteral("姜世杰"));
	arr_shuruishichang.append(object1_shuruishichang);

	QJsonObject object_shuruishichang;
	object_shuruishichang.insert("name", QStringLiteral("市场合作部"));
	object_shuruishichang.insert("subType", arr_shuruishichang);



	QJsonArray arr_shurui;
	arr_shurui.append(object_shuruiyanfa);
	arr_shurui.append(object_shuruishichang);
	QJsonObject object_shurui;
	object_shurui.insert("name", QStringLiteral("北斗数睿"));
	object_shurui.insert("subType", arr_shurui);
	main_json.append(object_shurui);


	QJsonArray arr_huicheyanfa;
	QJsonObject object1_huicheyanfa;
	object1_huicheyanfa.insert("name", QStringLiteral("孙爱超"));
	arr_huicheyanfa.append(object1_huicheyanfa);
	QJsonObject object2_huicheyanfa;
	object2_huicheyanfa.insert("name", QStringLiteral("蒋帅"));
	arr_huicheyanfa.append(object2_huicheyanfa);
	QJsonObject object3_huicheyanfa;
	object3_huicheyanfa.insert("name", QStringLiteral("李伟"));
	arr_huicheyanfa.append(object3_huicheyanfa);

	QJsonObject object_huicheyanfa;
	object_huicheyanfa.insert("name", QStringLiteral("产品研发部"));
	object_huicheyanfa.insert("subType", arr_huicheyanfa);


	QJsonArray arr_huicheshichang;
	QJsonObject object1_huicheshichang;
	object1_huicheshichang.insert("name", QStringLiteral("石磊"));
	arr_huicheshichang.append(object1_huicheshichang);

	QJsonObject object_huicheshichang;
	object_huicheshichang.insert("name", QStringLiteral("市场合作部"));
	object_huicheshichang.insert("subType", arr_huicheshichang);



	QJsonArray arr_huiche;
	arr_huiche.append(object_huicheyanfa);
	arr_huiche.append(object_huicheshichang);
	QJsonObject object_huiche;
	object_huiche.insert("name", QStringLiteral("北斗智联慧车"));
	object_huiche.insert("subType", arr_huiche);
	main_json.append(object_huiche);

	QJsonArray arr_yanfa;
	QJsonObject object1_yanfa;
	object1_yanfa.insert("name", QStringLiteral("陈春海"));
	arr_yanfa.append(object1_yanfa);
	QJsonObject object2_yanfa;
	object2_yanfa.insert("name", QStringLiteral("梁家振"));
	arr_yanfa.append(object2_yanfa);
	QJsonObject object3_yanfa;
	object3_yanfa.insert("name", QStringLiteral("隋明君"));
	arr_yanfa.append(object3_yanfa);
	QJsonObject object4_yanfa;
	object4_yanfa.insert("name", QStringLiteral("毛华伟"));
	arr_yanfa.append(object4_yanfa);
	QJsonObject object5_yanfa;
	object5_yanfa.insert("name", QStringLiteral("张宁"));
	arr_platform.append(object5_yanfa);

	QJsonObject object_yanfa;
	object_yanfa.insert("name", QStringLiteral("研发部"));
	object_yanfa.insert("subType", arr_yanfa);
	main_json.append(object_yanfa);

	m_recursionKey = recursionKey;
	beginResetModel();
	m_nodeList.clear();
	gen(0, main_json);
	endResetModel();
	countChanged();
}
void TaoJsonTreeModel::gen(int depth, const QJsonArray& dataArray)
{
    for (auto i : dataArray) {
        auto obj = i.toObject();
        obj[cDepthKey] = depth;
        obj[cExpendKey] = true;
        obj[cChildrenExpendKey] = false;
        obj[cHasChildendKey] = false;
        if (!m_recursionKey.isEmpty() && obj.contains(m_recursionKey)) {
            auto arr = obj.value(m_recursionKey).toArray();
            if (!arr.isEmpty()) {
                obj[cChildrenExpendKey] = true;
                obj[cHasChildendKey] = true;
                obj.remove(m_recursionKey);
                m_nodeList.append(obj);
                gen(depth + 1, arr);
                continue;
            }
        }
        m_nodeList.append(obj);
    }
}
bool TaoJsonTreeModel::saveToJson(const QString& jsonPath, bool compact) const
{
    QJsonArray arr;
    int depth = 0;
    for (int i = 0; i < m_nodeList.size(); ++i) {
        depth = m_nodeList.at(i).value(cDepthKey).toInt();
        if (depth == 0) {
            auto node = QJsonObject(m_nodeList.at(i));
            for (auto k : cFilterKeyList) {
                node.remove(k);
            }
            auto children = getChildren(i, depth);
            if (!children.isEmpty()) {
                node[m_recursionKey] = children;
            }
            arr.push_back(node);
        }
    }
    return writeJsonFile(jsonPath, arr, compact);
}

void TaoJsonTreeModel::clear()
{
    beginResetModel();
    m_nodeList.clear();
    endResetModel();
    countChanged();
}
QJsonArray TaoJsonTreeModel::getChildren(int parentIndex, int parentDepth) const
{
    QJsonArray arr;
    for (int i = parentIndex + 1; i < m_nodeList.size(); ++i) {
        int childDepth = m_nodeList.at(i).value(cDepthKey).toInt();
        if (childDepth == parentDepth + 1) {
            auto node = QJsonObject(m_nodeList.at(i));
            for (auto k : cFilterKeyList) {
                node.remove(k);
            }
            auto children = getChildren(i, childDepth);
            if (!children.isEmpty()) {
                node[m_recursionKey] = children;
            }
            arr.append(node);
        } else if (childDepth <= parentDepth) {
            break;
        }
    }
    return arr;
}

void TaoJsonTreeModel::setNodeValue(int index, const QString& key, const QVariant& value)
{
    if (index < 0 || index >= m_nodeList.size()) {
        return;
    }
    if (m_nodeList.at(index).value(key).toVariant() != value) {
        m_nodeList[index][key] = QJsonValue::fromVariant(value);
        emit dataChanged(Super::index(index), Super::index(index), { Qt::DisplayRole, Qt::EditRole });
    }
}

int TaoJsonTreeModel::addNode(int index, const QJsonObject& json)
{
    //countChanged();
    if (index < 0 || index >= m_nodeList.size()) {
        return addWithoutDepth(json);
    }
    int depth = m_nodeList.at(index).value(cDepthKey).toInt();
    int i = index + 1;
    for (; i < m_nodeList.size(); ++i) {
        if (m_nodeList.at(i).value(cDepthKey).toInt() <= depth) {
            break;
        }
    }
    auto obj = QJsonObject(json);
    obj[cDepthKey] = depth + 1;
    obj[cExpendKey] = true;
    obj[cChildrenExpendKey] = false;
    obj[cHasChildendKey] = false;
    beginInsertRows(QModelIndex(), i, i);
    m_nodeList.insert(i, obj);
    endInsertRows();
    countChanged();
    innerUpdate(index);
    expandTo(i);
    return i;
}

int TaoJsonTreeModel::addWithoutDepth(const QJsonObject& json)
{
    auto obj = QJsonObject(json);
    obj[cDepthKey] = 0;
    obj[cExpendKey] = true;
    obj[cChildrenExpendKey] = false;
    obj[cHasChildendKey] = false;
    beginInsertRows(QModelIndex(), m_nodeList.count(), m_nodeList.count());
    m_nodeList.append(obj);
    endInsertRows();
    countChanged();
    return m_nodeList.count() - 1;
}
void TaoJsonTreeModel::innerUpdate(int index)
{
    if (index < 0 || index >= m_nodeList.size()) {
        return;
    }
    int depth = m_nodeList.at(index).value(cDepthKey).toInt();
    int childrenCount = 0;
    for (int i = index + 1; i < m_nodeList.size(); ++i) {
        int childDepth = m_nodeList.at(i).value(cDepthKey).toInt();
        if (childDepth <= depth) {
            break;
        } else if (childDepth == depth + 1) {
            childrenCount++;
        }
    }
    setNodeValue(index, cHasChildendKey, childrenCount > 0);
}
void TaoJsonTreeModel::remove(int index)
{
    if (index < 0 || index >= m_nodeList.size()) {
        return;
    }
    int depth = m_nodeList.at(index).value(cDepthKey).toInt();
    int i = index + 1;
    for (; i < m_nodeList.size(); ++i) {
        int childDepth = m_nodeList.at(i).value(cDepthKey).toInt();
        if (childDepth <= depth) {
            break;
        }
    }
    beginRemoveRows({}, index, i - 1);
    for (int j = 0; j < i - index; ++j) {
        m_nodeList.removeAt(index);
    }
    endRemoveRows();
    countChanged();
    if (depth > 0) {
        for (int j = index - 1; j >= 0; --j) {
            if (depth - 1 == m_nodeList.at(j).value(cDepthKey).toInt()) {
                innerUpdate(j);
                break;
            }
        }
    }
}

QList<int> TaoJsonTreeModel::search(const QString& key, const QString& value, Qt::CaseSensitivity cs) const
{
    if (key.isEmpty() || value.isEmpty()) {
        return {};
    }
    QList<int> ans;
    ans.reserve(m_nodeList.size());
    for (int i = 0; i < m_nodeList.size(); ++i) {
        if (m_nodeList.at(i).value(key).toString().contains(value, cs)) {
            ans.push_back(i);
        }
    }
    return ans;
}

void TaoJsonTreeModel::expand(int index)
{
    if (index < 0 || index >= m_nodeList.size()) {
        return;
    }
    int depth = m_nodeList.at(index).value(cDepthKey).toInt();
    for (int i = index + 1; i < m_nodeList.size(); ++i) {
        int childDepth = m_nodeList.at(i).value(cDepthKey).toInt();
        if (childDepth <= depth) {
            break;
        } else if (childDepth > depth + 1) {
            continue;
        }
        setNodeValue(i, cExpendKey, true);
    }
    setNodeValue(index, cChildrenExpendKey, true);
}

void TaoJsonTreeModel::collapse(int index)
{
    if (index < 0 || index >= m_nodeList.size()) {
        return;
    }
    int depth = m_nodeList.at(index).value(cDepthKey).toInt();
    for (int i = index + 1; i < m_nodeList.size(); ++i) {
        int childDepth = m_nodeList.at(i).value(cDepthKey).toInt();
        if (childDepth <= depth) {
            break;
        }
        setNodeValue(i, cExpendKey, false);
        setNodeValue(i, cChildrenExpendKey, false);
    }
    setNodeValue(index, cChildrenExpendKey, false);
}

void TaoJsonTreeModel::expandTo(int index)
{
    if (index < 0 || index >= m_nodeList.size()) {
        return;
    }
    int depth = m_nodeList.at(index).value(cDepthKey).toInt();
    int parentDepth = depth - 1;
    QList<int> indexList;
    for (int i = index - 1; i >= 0 && parentDepth >= 0; --i) {
        int childDepth = m_nodeList.at(i).value(cDepthKey).toInt();
        if (childDepth == parentDepth) {
            indexList.push_back(i);
            parentDepth--;
        }
    }
    for (auto i : indexList) {
        expand(i);
    }
}

void TaoJsonTreeModel::expandAll()
{
    for (int i = 0; i < m_nodeList.size(); ++i) {
        if (true == m_nodeList.at(i).value(cHasChildendKey).toBool()) {
            setNodeValue(i, cChildrenExpendKey, true);
        }
        setNodeValue(i, cExpendKey, true);
    }
}

void TaoJsonTreeModel::collapseAll()
{
    for (int i = 0; i < m_nodeList.size(); ++i) {
        if (true == m_nodeList.at(i).value(cHasChildendKey).toBool()) {
            setNodeValue(i, cChildrenExpendKey, false);
        }
        if (0 < m_nodeList.at(i).value(cDepthKey).toInt()) {
            setNodeValue(i, cExpendKey, false);
        }
    }
}

int TaoJsonTreeModel::count() const
{
    return m_nodeList.size();
}

} // namespace TaoCommon
