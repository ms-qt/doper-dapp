#pragma execution_character_set("utf-8")
// folly
#include <folly/init/Init.h>
// 日志
#include "src/logger/Logger.h"
// Qt
#include <QApplication>
#include <QtWebEngine>
//rxqt
#include <rxqt.hpp>
// 线程
#include <src/tool/ThreadTool.h>
// app 信息 
#include "src/app/AppInfo.h"

#include <src/TaoJsonModel/TaoJsonModel>
// 表情
#include "src/emoji/emojimodel.h"
// 图片同步
#include "src/image/ImageProvider.h"
// 图片异步
#include "src/image/ImageAsyncImageProvider.h"
// 二维码
#include "src/image/QrCodeImageProvider.h"
// 用户凭证信息实体类
#include "src/local/db/CertificateDB.h"
// 用户凭证信息数据库
#include "src/local/db/CertificateBean.h"
// 登录处理器
#include "src/login/LoginHandler.h"
// model
#include "src/model/db/message/MessageBeanText.h"
#include "src/model/db/message/MessageListModel.h"
#include "src/model/db/room/RoomListModel.h"
#include "src/model/db/room/RoomP2PModel.h"

#include "src/model/db/task/TaskModel.h"
#include "src/model/db/task/TaskListModel.h"
#include "src/model/db/user/UserModel.h"

static void registertypes()
{
    qmlRegisterType<CertificateBean>("CertificateBean", 1, 0, "CertificateBean");
    qmlRegisterType<CertificateDB>("CertificateDB", 1, 0, "CertificateDB");
    qmlRegisterType<LoginHandler>("LoginHandler", 1, 0, "LoginHandler");

    qmlRegisterType<MessageBeanText>("MessageBeanText", 1, 0, "MessageBeanText");

    qmlRegisterType<TaskModel>("TaskModel", 1, 0, "TaskModel");
    qmlRegisterType<TaskListModel>("TaskListModel", 1, 0, "TaskListModel");
    qmlRegisterType<RoomListModel>("RoomListModel", 1, 0, "RoomListModel");
    qmlRegisterType<MessageListModel>("MessageListModel", 1, 0, "MessageListModel");

    qmlRegisterType<UserModel>("UserModel", 1, 0, "UserModel");
}

static void intiDatabase()
{
    // 初始化数据库
    QSqlDatabase database = QSqlDatabase::database();
    if (!database.isValid())
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        if (!database.isValid())
            qFatal("Cannot add database: %s", qPrintable(database.lastError().text()));
    }

    const QDir writeDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (!writeDir.mkpath("."))
        qFatal("Failed to create writable directory at %s", qPrintable(writeDir.absolutePath()));

    const QString fileName = writeDir.absolutePath() + "/app-database.sqlite3";

    qDebug() << "数据库位置 :  " << fileName;

    database.setDatabaseName(fileName);
    if (!database.open())
    {
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


    // 初始化数据库
    intiDatabase();


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
    engine.addImageProvider("imageAsync", asyncImageProvider);
    // 二维码
    QrCodeImageProvider *qrCodeImageProvider = new QrCodeImageProvider();
    engine.addImageProvider("imageQrCode", qrCodeImageProvider);

    // 用户信息
    CertificateDB *certificateDb = new CertificateDB();
    engine.rootContext()->setContextProperty("certificateDb", certificateDb);

//    UserModel *userModel = new UserModel();
//    engine.rootContext()->setContextProperty("userModel", userModel);
//
//    TaskModel *taskModel = new TaskModel();
//    engine.rootContext()->setContextProperty("taskModel", taskModel);
//
//    TaskListModel *taskListModel = new TaskListModel();
//    engine.rootContext()->setContextProperty("taskListModel", taskListModel);
//
//    MessageListModel *messageListModel = new MessageListModel();
//    engine.rootContext()->setContextProperty("messageListModel", messageListModel);
//
//    RoomListModel *roomListModel = new RoomListModel();
//    engine.rootContext()->setContextProperty("roomListModel", roomListModel);


    engine.load(url);
    return app.exec();
}
