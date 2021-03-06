﻿#pragma execution_character_set("utf-8")
#include <QQmlImageProviderBase>
#include <QQuickAsyncImageProvider>
#include <QQuickImageProvider>

class QNetworkAccessManager;

// 图片加载 同步

class ImageProvider : public QQuickImageProvider
{
public:
    ImageProvider(ImageType type, Flags flags = 0);

    ~ImageProvider();

    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize);

protected:
    QNetworkAccessManager *manager;
};
