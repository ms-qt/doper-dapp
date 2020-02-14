//
// Created by 毛华伟 on 2020/1/16.
//

#include "NotificationQuickView.h"


NotificationQuickView::NotificationQuickView()
{

    this->rootContext()->setContextProperty("notificationWindow", this);

    qmlRegisterType<UserModel>("UserModel", 0, 1, "UserModel");
    qmlRegisterType<MessageBeanText>("MessageBeanText", 0, 1, "MessageBeanText");
    qmlRegisterType<CertificateDB>("CertificateDB", 0, 1, "CertificateDB");

    // 文字消息model
    MessagTextModel *messagTextModel = new MessagTextModel();
    this->rootContext()->setContextProperty("messagTextModel", messagTextModel);

    // 消息列表model
    MessageListModel *messageListModel = new MessageListModel();
    this->rootContext()->setContextProperty("messageListModel", messageListModel);

    // 任务model
    TaskModel *taskModel = new TaskModel();
    this->rootContext()->setContextProperty("taskModel", taskModel);

    // 任务列表model
    TaskListModel *taskListModel = new TaskListModel();
    this->rootContext()->setContextProperty("taskListModel", taskListModel);

    // 房间列表
    RoomListModel *roomListModel = new RoomListModel();
    this->rootContext()->setContextProperty("roomListModel", roomListModel);

    // 两人对话房间
    RoomP2PModel *roomP2PModel = new RoomP2PModel();
    this->rootContext()->setContextProperty("roomP2PModel", roomP2PModel);

    // 通知消息
    NotificationsManager *notificationsManager = new NotificationsManager();
    this->rootContext()->setContextProperty("notificationsManager", notificationsManager);

    UserModel *userModel = new UserModel();
    this->rootContext()->setContextProperty("userModel", userModel);

    // 凭证数据库
    CertificateDB *certificateDb = new CertificateDB();
    this->rootContext()->setContextProperty("certificateDb", certificateDb);

    // 查询数据库末尾数据
    CertificateBean *certificateBean = certificateDb->queryLaster();
    this->rootContext()->setContextProperty("certificateBean", certificateBean);


    // 注册剪切板
    Clipboard *clipboard = new Clipboard();
    this->rootContext()->setContextProperty("clipboard", clipboard);

    connect(UIModelProxy::GetInstance(), SIGNAL(loginSuccess()), this, SLOT(loginSuccess()));


    QQmlEngine *engine = this->engine();
    engine->addImportPath("qrc:/qml");

    imageProvider = new ImageProvider(QQmlImageProviderBase::Image);
    engine->addImageProvider("imageProvider", imageProvider);

    asyncImageProvider = new AsyncImageProvider();
    engine->addImageProvider("async", new AsyncImageProvider);


    actionOpenNotificationPanel = new QAction(tr("打开通知面板"));
    actionOpenMainControllPanel = new QAction(tr("打开主控面板"));
    actionExit = new QAction(tr("退出"));
    actionOnLine = new QAction(tr("在线"));
    // 隐身
    actionStealth = new QAction(tr("隐身"));
    // 离线
    actionOffline = new QAction(tr("离线"));
    // 离开
    actionLeave = new QAction(tr("离开"));
    // 菜单
    menu = new QMenu();
    menu->addAction(actionOpenNotificationPanel);
    menu->addAction(actionOpenMainControllPanel);
    menu->addAction(actionOnLine);
    menu->addAction(actionStealth);
    menu->addAction(actionLeave);
    menu->addAction(actionOffline);
    menu->addAction(actionExit);

    systemTrayIcon = new QSystemTrayIcon();
    systemTrayIcon->setIcon(QIcon(":images/img_icon_blue.png"));
    systemTrayIcon->setContextMenu(menu);

    connect(actionExit, &QAction::triggered, qApp, &QCoreApplication::quit);
    connect(systemTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this,
            SLOT(activated(QSystemTrayIcon::ActivationReason)));
    connect(actionOpenMainControllPanel, SIGNAL(triggered(bool)), this, SLOT(openMainControllerPaneltriggered(bool)));


    // 设置登录的 qml url
    const QUrl url(QStringLiteral("qrc:/qml/NotificationPanel/NotificationPanelHome.qml"));
    this->setFlags(Qt::FramelessWindowHint);
    this->setSource(url);
    this->setResizeMode(SizeRootObjectToView);
    QDesktopWidget *desktopWidget = QApplication::desktop();
    //获取可用桌面大小
    QRect deskRect = desktopWidget->availableGeometry();
    // 设置
    this->setX(deskRect.width() / 5 * 4);
    this->setY(100);

    this->setMinimumWidth(deskRect.width() / 6);
    this->setMaximumWidth(deskRect.width() / 6 * 2);
    this->setMinimumHeight(deskRect.height() / 5 * 3);
    this->setMaximumHeight(deskRect.height());
}

NotificationQuickView::~NotificationQuickView()
{
}

// 登录成功,显示通知面板
void NotificationQuickView::loginSuccess()
{
    qDebug() << " NotificationQuickView::loginSuccess() ";
    this->show();
    systemTrayIcon->show();
}

void NotificationQuickView::activated(QSystemTrayIcon::ActivationReason reason)
{
    qDebug() << "activated";
    show();
    raise();
    requestActivate();
}

void NotificationQuickView::openMainControllerPaneltriggered(bool checked)
{
    qDebug() << "openMainControllerPaneltriggered : " << checked;
    emit UIModelProxy::GetInstance()->openMainControllerPanel();
}
