import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3


import Toou2D 1.0

import UserModel 1.0
import TaskListModel 1.0
import TaskModel 1.0
import MessageListModel 1.0
import RoomListModel 1.0
import MessageTextModel 1.0


ApplicationWindow {

    id:rootWindow
    property int rootWindowWidth : 380
    property int rootWindowHeight : 600

    visible: true
    width: rootWindowWidth
    height: rootWindowHeight


    minimumWidth:  rootWindow.width/2
    minimumHeight: rootWindow.height/2

    flags: Qt.Window | Qt.FramelessWindowHint


    T2DWorld{
        //appStartupTheme: "Solarized"
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

        // 用户id TODO 为了调试方便先写死
        property string userid:"29c799c72e13f5bd7af95c60b4187318"



    }

    UserModel{
        id:userModel
    }

    TaskListModel{
        id:taskListModel
    }

    TaskModel{
        id:taskModel
    }
    MessageListModel{
        id:messageListModel
    }
    RoomListModel{
        id:roomListModel
    }

    MessageTextModel{
        id:messageTextModel
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

        target=rootWindow
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

        TPopoverElement{
            text: "Quiet"
            otherData: "Quiet";
            iconSource: TThemeManager.appTheme === otherData ? TAwesomeType.FA_check_circle_o : TAwesomeType.FA_circle_o
        }


        onTriggered: TThemeManager.appTheme = modelData.otherData;
    }






    property var target
    property point startPoint: Qt.point(0, 0);
    property point fixedPont: Qt.point(0, 0);


    /*
                 ↑     ↑     ↑
               ←|1|   |2|   |3|→
               ←|4|   |5|   |6|→
               ←|7|   |8|   |9|→
                 ↓     ↓     ↓
                分8个缩放区域
                |5|为拖动区域
           target       缩放目标
           startPoint   鼠标起始点
           fixedPont    用于固定窗口的点
           每一个area   大小 8 x 8
    */


    MouseArea
    {
        id: area1
        x: 0
        y: 0
        width: 8
        height: 8
        hoverEnabled: true

        onEntered: cursorShape = Qt.SizeFDiagCursor;
        onExited: cursorShape = Qt.ArrowCursor;
        onPressed: startPoint = Qt.point(mouseX, mouseY);
        onPositionChanged:
        {
            if(pressed)
            {
                var offsetX = mouse.x - startPoint.x;
                var offsetY = mouse.y - startPoint.y;
                if ((target.width - offsetX) >= target.minimumWidth) //如果本次调整小于最小限制，则调整为最小
                {
                    target.width -= offsetX;
                    target.x += offsetX;
                }
                else
                {
                    target.x += (target.width - target.minimumWidth);
                    target.width -= (target.width - target.minimumWidth);
                }

                if ((target.height - offsetY) >= target.minimumHeight && offsetY != 0)
                {
                    target.height -= offsetY;
                    target.y += offsetY;
                }
            }
        }
    }

    MouseArea
    {
        id: area2
        x: 8
        y: 0
        width: target.width - 16
        height: 8
        hoverEnabled: true

        onEntered: cursorShape = Qt.SizeVerCursor;
        onExited: cursorShape = Qt.ArrowCursor;
        onPressed: startPoint = Qt.point(mouseX, mouseY);
        onPositionChanged:
        {
            if(pressed)
            {
                var offsetY = mouse.y - startPoint.y;
                if ((target.height - offsetY) >= target.minimumHeight && offsetY != 0)
                {
                    target.height -= offsetY;
                    target.y += offsetY;
                }
            }
        }
    }

    MouseArea
    {
        id: area3
        x: target.width - 8
        y: 0
        width: 8
        height: 8
        hoverEnabled: true

        onEntered: cursorShape = Qt.SizeBDiagCursor;
        onExited: cursorShape = Qt.ArrowCursor
        onPressed:
        {
            startPoint = Qt.point(mouseX, mouseY);
            fixedPont = Qt.point(target.x, target.y)
        }
        onPositionChanged:
        {
            if(pressed)
            {
                var offsetX = mouse.x - startPoint.x;
                var offsetY = mouse.y - startPoint.y;
                print (offsetX, offsetY)
                if ((target.width + offsetX) >= target.minimumWidth && offsetX != 0)
                {
                    target.width += offsetX;
                    target.x = fixedPont.x;
                }
                if ((target.height - offsetY) >= target.minimumHeight && offsetY != 0)
                {
                    target.height -= offsetY;
                    target.y += offsetY;
                }
            }
        }
    }

    MouseArea
    {
        id: area4
        x: 0
        y: 8
        width: 8
        height: target.height - 16
        hoverEnabled: true

        onEntered: cursorShape = Qt.SizeHorCursor;
        onExited: cursorShape = Qt.ArrowCursor;
        onPressed:
        {
            startPoint = Qt.point(mouseX, mouseY);
        }
        onPositionChanged:
        {
            if(pressed)
            {
                var offsetX = mouse.x - startPoint.x;
                if ((target.width - offsetX) >= target.minimumWidth)
                {
                    target.width -= offsetX;
                    target.x += offsetX;
                }
            }
        }
    }



    MouseArea
    {
        id: area6
        x: target.width - 8
        y: 8
        width: 8
        height: target.height - 16
        hoverEnabled: true
        property real fixedX: 0;

        onEntered: cursorShape = Qt.SizeHorCursor;
        onExited: cursorShape = Qt.ArrowCursor;
        onPressed:
        {
            startPoint = Qt.point(mouseX, mouseY);
            fixedPont = Qt.point(target.x, target.y)
        }
        onPositionChanged:
        {
            if(pressed)
            {
                var offsetX = mouse.x - startPoint.x;
                if ((target.width + offsetX) >= target.minimumWidth && offsetX != 0)
                {
                    target.width += offsetX;
                    target.x = fixedPont.x;
                }
            }
        }
    }

    MouseArea
    {
        id: area7
        x: 0
        y: target.height - 8
        width: 8
        height: target.height - 16
        hoverEnabled: true
        property real fixedX: 0;

        onEntered: cursorShape = Qt.SizeBDiagCursor;
        onExited: cursorShape = Qt.ArrowCursor;
        onPressed:
        {
            startPoint = Qt.point(mouseX, mouseY);
            fixedPont = Qt.point(target.x, target.y)
        }
        onPositionChanged:
        {
            if (pressed)
            {
                var offsetX = mouse.x - startPoint.x;
                var offsetY = mouse.y - startPoint.y;
                if ((target.width - offsetX) >= target.minimumWidth && offsetX != 0)
                {
                    target.width -= offsetX;
                    target.x += offsetX;
                }
                if ((target.height + offsetY) >= target.minimumHeight && offsetY != 0)
                {
                    target.height += offsetY;
                    target.y = fixedPont.y;
                }
            }
        }
    }

    MouseArea
    {
        id: area8
        x: 8
        y: target.height - 8
        width: target.height - 16
        height: 8
        hoverEnabled: true
        property real fixedX: 0;

        onEntered: cursorShape = Qt.SizeVerCursor;
        onExited: cursorShape = Qt.ArrowCursor;
        onPressed:
        {
            startPoint = Qt.point(mouseX, mouseY);
            fixedPont = Qt.point(target.x, target.y)
        }
        onPositionChanged:
        {
            if (pressed)
            {
                var offsetY = mouse.y - startPoint.y;
                if ((target.height + offsetY) >= target.minimumHeight && offsetY != 0)
                {
                    target.height += offsetY;
                    target.y = fixedPont.y;
                }
            }
        }
    }

    MouseArea
    {
        id: area9
        x: target.width - 8
        y: target.height - 8
        width: 8
        height: 8
        hoverEnabled: true

        onEntered: cursorShape = Qt.SizeFDiagCursor;
        onExited: cursorShape = Qt.ArrowCursor
        onPressed:
        {
            startPoint = Qt.point(mouseX, mouseY);
            fixedPont = Qt.point(target.x, target.y)
        }
        onPositionChanged:
        {
            if(pressed)
            {
                var offsetX = mouse.x - startPoint.x;
                var offsetY = mouse.y - startPoint.y;
                if ((target.width + offsetX) >= target.minimumWidth && offsetX != 0)
                {
                    target.width += offsetX;
                    target.x = fixedPont.x;
                }
                if ((target.height + offsetY) >= target.minimumHeight && offsetY != 0)
                {
                    target.height += offsetY;
                    target.y = fixedPont.y;
                }
            }
        }
    }
}
