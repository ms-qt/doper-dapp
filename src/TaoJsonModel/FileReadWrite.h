#pragma once
#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
namespace TaoCommon
{
    //读取文件，返回byte数组
    static bool readFile(const QString &filePath, QByteArray &content)
    {
        QFile file(filePath);
        if (!file.open(QFile::ReadOnly))
        {
            qWarning() << "open file " << filePath << "failed:" << file.errorString();
            return false;
        }
        content = file.readAll();
        file.close();
        return true;
    }
    //读取json字节数组，返回jsonDDocument
    static bool readJson(const QByteArray &data, QJsonDocument &doc)
    {
        QJsonParseError err;
        doc = QJsonDocument::fromJson(data, &err);
        if (doc.isNull())
        {
            qWarning() << "parse json failed:" << err.errorString();
            return false;
        }
        return true;
    }
    //读取json字节数组，返回jsonArray
    static bool readJson(const QByteArray &data, QJsonArray &array)
    {
        QJsonDocument doc;
        bool ok = readJson(data, doc);
        if (ok)
        {
            array = doc.array();
        }
        return ok;
    }
    //读取json字节数组，返回json对象
    static bool readJson(const QByteArray &data, QJsonObject &object)
    {
        QJsonDocument doc;
        bool ok = readJson(data, doc);
        if (ok)
        {
            object = doc.object();
        }
        return ok;
    }
    //读取json文件,返回jsonDocument
    static bool readJsonFile(const QString &filePath, QJsonDocument &jsonDoc)
    {
        QByteArray data;
        if (!readFile(filePath, data))
        {
            return false;
        }
        return readJson(data, jsonDoc);
    }
    //读取json文件,返回jsonobject
    static bool readJsonFile(const QString &filePath, QJsonObject &jsonObj)
    {
        QByteArray data;
        if (!readFile(filePath, data))
        {
            return false;
        }
        return readJson(data, jsonObj);
    }
    //读取json文件,返回jsonarray
    static bool readJsonFile(const QString &filePath, QJsonArray &jsonArray)
    {
        QByteArray data;
        if (!readFile(filePath, data))
        {
            return false;
        }
        return readJson(data, jsonArray);
    }
    static bool writeFile(const QString &filePath, const QByteArray &content)
    {
        QFile file(filePath);
        if (!file.open(QFile::WriteOnly))
        {
            qWarning() << "open file " << filePath << "failed:" << file.errorString();
            return false;
        }
        file.write(content);
        file.close();
        return true;
    }
    // compact ,压缩空格和换行符，indented,json标准格式，包括空格和换行符
    static bool writeJsonFile(const QString &filePath, const QJsonDocument &doc, bool compact = true)
    {
        return writeFile(filePath, doc.toJson(compact ? QJsonDocument::Compact : QJsonDocument::Indented));
    }
    static bool writeJsonFile(const QString &filePath, const QJsonArray &jsonArray, bool compact = true)
    {
        return writeJsonFile(filePath, QJsonDocument(jsonArray), compact);
    }
    static bool writeJsonFile(const QString &filePath, const QJsonObject &jsonObj, bool compact = true)
    {
        return writeJsonFile(filePath, QJsonDocument(jsonObj), compact);
    }

} // namespace TaoCommon
