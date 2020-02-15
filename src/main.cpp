#pragma execution_character_set("utf-8")

// folly
#include <folly/init/Init.h>
// 日志
#include "src/logger/Logger.h"

// Qt
#include <QApplication>
#include <QtWebEngine>


#include <src/net/NetWorkManager.h>

#include <src/tool/ThreadTool.h>
#include "src/app/AppInfo.h"

#include <src/TaoJsonModel/TaoJsonModel>

#include "src/emoji/emojimodel.h"

// 图片同步
#include "src/image/ImageProvider.h"
// 图片异步
#include "src/image/ImageAsyncImageProvider.h"
// 二维码
#include "src/image/QrCodeImageProvider.h"


static void registertypes(){
   // qmlRegisterType<TreeElement>("foo", 1, 0, "TreeElement");
}

static void connectToDatabase()
{
    QSqlDatabase database = QSqlDatabase::database();
    if (!database.isValid()) {
        database = QSqlDatabase::addDatabase("QSQLITE");
        if (!database.isValid())
            qFatal("Cannot add database: %s", qPrintable(database.lastError().text()));
    }

    const QDir writeDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (!writeDir.mkpath("."))
        qFatal("Failed to create writable directory at %s", qPrintable(writeDir.absolutePath()));

    // Ensure that we have a writable location on all devices.
    const QString fileName = writeDir.absolutePath() + "/chat-database.sqlite3";
    // When using the SQLite driver, open() will create the SQLite database if it doesn't exist.
    database.setDatabaseName(fileName);
    if (!database.open()) {
        qFatal("Cannot open database: %s", qPrintable(database.lastError().text()));
        QFile::remove(fileName);
    }
}

Q_COREAPP_STARTUP_FUNCTION(registertypes)

int main(int argc, char *argv[])
{
    // 高分辨率
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    // 设置代理
    QNetworkProxyFactory::setUseSystemConfiguration(true);
    // app
    QApplication app(argc, argv);
    // 初始化日志
    Logger::initLog();
    //树形组件注册
    TaoCommon::moduleRegister();
    // 初始化folly linux 需要
    folly::init(&argc, &argv);

    // 设置组织等信息
    app.setOrganizationName(ORGANIZATION);
    app.setOrganizationDomain(ORGANIZATION);
    // 设置app名称
    app.setApplicationName(APP_NAME);
    app.setWindowIcon(QIcon(":/assets/image/icon.png"));

    // rxqt loop
    rxqt::run_loop rxqt_run_loop;
    // main线程
    rxcpp::observe_on_one_worker main_thread = rxqt_run_loop.observe_on_run_loop();
    // 初始化UI线程
    ThreadTool::getInstance()->main_thread = main_thread;

    // 注册表情
    qRegisterMetaTypeStreamOperators<Emoji>();
    
    // 初始化WebEngine
    QtWebEngine::initialize();

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl)
                     {
                         if (!obj && url == objUrl)
                             QCoreApplication::exit(-1);
                     }, Qt::QueuedConnection);


    // qml 路径
    engine.addImportPath("qrc:/qml");

    // 同步加载图片
    ImageProvider *imageProvider = new ImageProvider(QQmlImageProviderBase::Image);
    engine.addImageProvider("imageSync", imageProvider);
    // 异步加载
    AsyncImageProvider *asyncImageProvider = new AsyncImageProvider();
    engine.addImageProvider("imageAsyn", asyncImageProvider);
    // 二维码
    QrCodeImageProvider *qrCodeImageProvider = new QrCodeImageProvider();
    engine.addImageProvider("imageQrCode", qrCodeImageProvider);

    engine.load(url);
    return app.exec();
}
