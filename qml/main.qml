import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3


import Toou2D 1.0

ApplicationWindow {

    id:rootWindow
    property int rootWindowWidth : 380
    property int rootWindowHeight : 600

    visible: true
    width: rootWindowWidth
    height: rootWindowHeight

    flags: Qt.Window | Qt.FramelessWindowHint


    T2DWorld{
        appStartupTheme: "Solarized"
        appThemePaths: [
            "qrc:/themes/"
        ]
        mouseAreaCursorShape: Qt.PointingHandCursor
    }


    // 全局变量
    property TObject global : TObject{
        // title 高度
        property int windowTitleHeight: 50
        // 分割线颜色
        property color name: "#bdbdbd"
        // 是否登录
        property bool loginSuccess: false

        // 用户id

        property string userid:"maohuawei"



    }

    property int xMouse
    property int yMouse

    MouseArea { //为窗口添加鼠标事件
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton //只处理鼠标左键
        onPressed: { //接收鼠标按下事件
            xMouse = mouse.x
            yMouse = mouse.y
        }
        onPositionChanged: { //鼠标按下后改变位置
            rootWindow.x = rootWindow.x + (mouse.x - xMouse)
            rootWindow.y = rootWindow.y + (mouse.y - yMouse)
        }
    }


    function doMinimized() {
        flags = Qt.Window | Qt.WindowFullscreenButtonHint | Qt.CustomizeWindowHint | Qt.WindowMinimizeButtonHint
        visibility = Window.Minimized
    }
    onVisibilityChanged: {
        if (Window.Minimized !== visibility) {
            flags = Qt.Window | Qt.FramelessWindowHint
        }
    }


    // 托盘
    Tray{

    }

    // 关于
    About{
        id:about
    }

    // 标题
    WindowTitle{
        id:windowTitle
        width: parent.width
        height:rootWindow.global.windowTitleHeight
    }


    function loginSuccess()
    {
        rootWindow.global.loginSuccess=true;
        rootWindowWidth=Screen.width/5*1.3
        rootWindowHeight= Screen.height/6*5

        rootWindow.x=Screen.width/5*3
        rootWindow.y=100
    }

    LoginHome{
        visible: !rootWindow.global.loginSuccess
        anchors.top: windowTitle.bottom
        width: parent.width
        height: parent.height-windowTitle.height
    }

    NotificationHome{
        visible: rootWindow.global.loginSuccess
        anchors.top: windowTitle.bottom
        width: parent.width
        height: parent.height-windowTitle.height
    }


    MainWindow{

        visible: true

    }


    // 加载中
    BaseLoading{
        visible: false
        objectName: "baseLoadingObject"
        id:baseLoading
        width: parent.width
        height: parent.height
        anchors.centerIn: parent

        Layout.margins: 10
        implicitWidth: 30
        implicitHeight: 30

        function show()
        {
            baseLoading.visible=true
        }
        function hide()
        {
            baseLoading.visible=false
        }
    }

    TPopoverMenu{
        id:themePopover;

        TPopoverElement{
            text: "默认"
            otherData: "";
            iconSource: TThemeManager.appThemeInvalid ? TAwesomeType.FA_check_circle_o : TAwesomeType.FA_circle_o
        }

        TPopoverElement{
            text: "宁静"
            otherData: "Solarized";
            iconSource: TThemeManager.appTheme === otherData ? TAwesomeType.FA_check_circle_o : TAwesomeType.FA_circle_o
        }

        TPopoverElement{
            text: "炫黑"
            otherData: "Dark";
            iconSource: TThemeManager.appTheme === otherData ? TAwesomeType.FA_check_circle_o : TAwesomeType.FA_circle_o
        }

        onTriggered: TThemeManager.appTheme = modelData.otherData;
    }




}
