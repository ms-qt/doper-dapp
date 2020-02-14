#pragma execution_character_set("utf-8")

#include <folly/init/Init.h>
#include <src/logger/Logger.h>
#include <src/app/AppQuickViewManager.h>
#include <QApplication>
#include <QtWebEngine>
#include <src/net/NetWorkManager.h>
#include "src/app/NotificationQuickView.h"
#include <src/tool/ThreadTool.h>
#include <src/model/db/user/UserModel.h>
#include <src/config/__APP_CONFIG__.h>
#include <src/TaoJsonModel/TaoJsonModel>
#include "src/emoji/emojimodel.h"

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
    // UI init

    //TODO
    //AppQuickViewManager::GetInstance()->init();

    //AppQuickViewManager::GetInstance()->getMainQuickView()->show();



    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                if (!obj && url == objUrl)
                    QCoreApplication::exit(-1);
            }, Qt::QueuedConnection);
    engine.load(url);



    // 初始化WebEngine
    QtWebEngine::initialize();


    return app.exec();
}
