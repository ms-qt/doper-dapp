//
// Created by 毛华伟 on 2020/1/7.
//

#include "MainQuickView.h"

MainQuickView::MainQuickView()
{
    this->rootContext()->setContextProperty("mainWindow", this);

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

    this->rootContext()->setContextProperty("notificationWindow", this);




    QList<QObject *> homeLeftMenuModelList;

    MainLeftMenu *homeLeftMenuModelInfo = new MainLeftMenu();
    homeLeftMenuModelInfo->setName("信息");
    homeLeftMenuModelInfo->setIconUrl("qrc:/images/img_info.png");
    homeLeftMenuModelList.append(homeLeftMenuModelInfo);


    MainLeftMenu *homeLeftMenuModelEmail = new MainLeftMenu();
    homeLeftMenuModelEmail->setName("邮件");
    homeLeftMenuModelEmail->setIconUrl("qrc:/images/img_email.png");
    homeLeftMenuModelList.append(homeLeftMenuModelEmail);


    this->rootContext()->setContextProperty("homeLeftMenuModel", QVariant::fromValue(homeLeftMenuModelList));
    
    connect(UIModelProxy::GetInstance(), SIGNAL(enterRoom(QString)), this, SLOT(enterRoom(QString)));
    connect(UIModelProxy::GetInstance(), SIGNAL(enterTask(QString)), this, SLOT(enterTask(QString)));
    connect(UIModelProxy::GetInstance(), SIGNAL(openMainControllerPanel()), this, SLOT(openMainControllerPanel()));
    connect(UIModelProxy::GetInstance(), SIGNAL(sendMessage(QString)), this, SLOT(sendMessage(QString)));

    QQmlEngine *engine = this->engine();
    engine->addImportPath("qrc:/qml");

    AsyncImageProvider *asyncImageProvider = new AsyncImageProvider();
    engine->addImageProvider("async", asyncImageProvider);

    // qml url
    const QUrl url(QStringLiteral("qrc:/qml/MainControlPanel/Main.qml"));
    this->setSource(url);
    this->setResizeMode(SizeRootObjectToView);
    QDesktopWidget *desktopWidget = QApplication::desktop();
    //获取可用桌面大小
    QRect deskRect = desktopWidget->availableGeometry();
    //获取主屏幕分辨率
    QRect screenRect = desktopWidget->screenGeometry();
    //获取屏幕数量
    int nScreenCount = desktopWidget->screenCount();

    qDebug() << "width:" << deskRect.width();
    qDebug() << "height:" << deskRect.height();
    qDebug() << "屏幕数量:" << nScreenCount;
    // 设置居中
    this->setX(deskRect.width() / 2 - this->width() / 2);
    this->setY(deskRect.height() / 2 - this->height() / 2);
}

void MainQuickView::enterRoom(QString roomId)
{
    qDebug() << "MainQuickView enterRoom " << roomId;
    show();
}

void MainQuickView::enterTask(QString taskId)
{
    qDebug() << "MainQuickView enterRoom " << taskId;
    show();
}

void MainQuickView::openMainControllerPanel()
{
    qDebug() << "MainQuickView openMainControllerPanel ";
    show();
}


void MainQuickView::sendMessage(QString userId)
{
    show();
}