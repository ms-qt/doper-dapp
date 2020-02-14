#include <QQuickImageProvider>
#include <QQuickAsyncImageProvider>
#include <QQmlImageProviderBase>

class QNetworkAccessManager;

class ImageProvider : public QQuickImageProvider
{
public:
    ImageProvider(ImageType type, Flags flags = 0);

    ~ImageProvider();

    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize);

protected:
    QNetworkAccessManager *manager;
};