//
// Created by 毛华伟 on 2020/1/16.
//

#include "LoginQuickView.h"
#include <QWidget>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>

LoginQuickView::LoginQuickView()
{
    //qrcode image register
    QQmlEngine *engine = this->engine();

    engine->addImportPath("qrc:/qml");
    engine->addImageProvider(QLatin1String("qrcode"), new QrCodeImageProvider());
    this->engine()->addImportPath("qrc:/toou2d");
    this->engine()->addImportPath(":/toou2d");
    this->engine()->addPluginPath(":/toou2d");

    // 设置登录的 qml url
    const QUrl url(QStringLiteral("qrc:/qml/Login/LoginHome.qml"));
    this->setSource(url);
    this->setResizeMode(SizeRootObjectToView);

    QDesktopWidget *desktopWidget = QApplication::desktop();
    //获取可用桌面大小
    QRect deskRect = desktopWidget->availableGeometry();

    // 去掉边框
    this->setFlags(Qt::FramelessWindowHint);


    this->setWidth(360);
    this->setHeight(530);


    // 设置居中
    this->setX(deskRect.width() / 2 - this->width() / 2);
    this->setY(deskRect.height() / 2 - this->height() / 2);

    this->show();

    // 查找登录界面加载中控件实例
    loadingQrCodeObject = this->findChild<QObject *>("loadingQrCodeObject");
    // 登录加载中...
    loadingLoginHomeObject = this->findChild<QObject *>("loadingLoginHomeObject");
    // 查找登录界面提示控件实例
    textHintObject = this->findChild<QObject *>("textHintObject");
    // 登录表单信息
    columnLayoutLoginHomeFromInfo = this->findChild<QObject *>("columnLayoutLoginHomeFromInfo");

    // 凭证数据库
    CertificateDB *certificateDb = new CertificateDB();
    this->rootContext()->setContextProperty("certificateDb", certificateDb);

    // 注册im操作模型
    IMModel *imModel = new IMModel();
    this->rootContext()->setContextProperty("imModel", imModel);
    //
    this->rootContext()->setContextProperty("loginWindow", this);

    qmlRegisterType<CertificateDB>("CertificateDB", 0, 1, "CertificateDB");
    // 查询数据库末尾数据
    CertificateBean *certificateBean = certificateDb->queryLaster();
    this->rootContext()->setContextProperty("certificateBean", certificateBean);

    QString username = certificateBean->username();
    QString password = certificateBean->password();
    bool save_password = certificateBean->save_password();
    bool auto_login = certificateBean->auto_login();


    // 登录信息回显
    setUsername(username);
    setPassword(password);
    setSavePassword(save_password);
    setAutoLogin(auto_login);

    connect(UIModelProxy::GetInstance(), SIGNAL(loginSuccess()), this, SLOT(loginSuccess()));
    connect(UIModelProxy::GetInstance(), SIGNAL(startLogin()), this, SLOT(startLogin()));

    actionExit = new QAction();
    // 退出 字符串不能在此处写
    actionExit->setText(tr("退出"));

    // 菜单
    menu = new QMenu();
    menu->addAction(actionExit);

    // 托盘
    systemTrayIcon = new QSystemTrayIcon();
    systemTrayIcon->setContextMenu(menu);

    systemTrayIcon->setIcon(QIcon(":images/img_icon_blue.png"));
    // 显示托盘ICON
    systemTrayIcon->show();

    // connect(pTrayMenu, SIGNAL(showWindow()), this, SLOT(showWindow()));
    // connect(pTrayMenu, SIGNAL(QuitApp()), this, SLOT(QuitApp()));
    // connect(systemTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(onActivated(QSystemTrayIcon::ActivationReason)));

    connect(actionExit, &QAction::triggered, qApp, &QCoreApplication::quit);
    connect(systemTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this,
            SLOT(activated(QSystemTrayIcon::ActivationReason)));

}

void LoginQuickView::activated(QSystemTrayIcon::ActivationReason reason)
{

    qDebug() << "activated";
    show();
    raise();
    requestActivate();

}


LoginQuickView::~LoginQuickView()
{

}

void LoginQuickView::homeShowDialog()
{
    QMetaObject::invokeMethod(
            loadingLoginHomeObject,
            "show"
    );
}

void LoginQuickView::homeHideDialog()
{
    QMetaObject::invokeMethod(
            loadingLoginHomeObject,
            "hide");
}

void LoginQuickView::qrCodeShowDialog()
{
    QMetaObject::invokeMethod(
            loadingQrCodeObject,
            "show"
    );
}

void LoginQuickView::qrCodeHideDialog()
{
    QMetaObject::invokeMethod(
            loadingQrCodeObject,
            "hide");
}


void LoginQuickView::setHintText(QString text)
{


    QMetaObject::invokeMethod(
            textHintObject,
            "setText",
            Q_ARG(QVariant, QVariant(text))
    );
}


void LoginQuickView::setUsername(QString username)
{

    qDebug() << "setUsername  : " << username;

    QMetaObject::invokeMethod(
            columnLayoutLoginHomeFromInfo,
            "setUsername",
            Q_ARG(QVariant, QVariant(username))
    );
}

void LoginQuickView::setPassword(QString password)
{
    qDebug() << "setPassword  : " << password;
    QMetaObject::invokeMethod(
            columnLayoutLoginHomeFromInfo,
            "setPassword",
            Q_ARG(QVariant, QVariant(password))
    );
}

void LoginQuickView::setSavePassword(bool savepassword)
{
    QMetaObject::invokeMethod(
            columnLayoutLoginHomeFromInfo,
            "savePassword",
            Q_ARG(QVariant, QVariant(savepassword))
    );
}

void LoginQuickView::setAutoLogin(bool autologin)
{
    QMetaObject::invokeMethod(
            columnLayoutLoginHomeFromInfo,
            "autoLogin",
            Q_ARG(QVariant, QVariant(autologin))
    );
}


void LoginQuickView::loginSuccess()
{
    qDebug() << " LoginQuickView::loginSuccess() ";


    QMetaObject::invokeMethod(
            loadingLoginHomeObject,
            "hide"
    );


    this->hide();
    this->close();
    systemTrayIcon->hide();

}

void LoginQuickView::startLogin()
{
    homeShowDialog();
}