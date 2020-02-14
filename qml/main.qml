import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12

import Toou2D 1.0

ApplicationWindow {

    id:rootWindow
    property int rootWindowWidth : 320
    property int rootWindowHeight : 480

    visible: true

    width: rootWindowWidth
    height: rootWindowHeight

    flags: Qt.FramelessWindowHint

    T2DWorld{
        appStartupTheme: "Solarized"
        appThemePaths: [
            "qrc:/themes/"
        ]
        mouseAreaCursorShape: Qt.PointingHandCursor
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

    // 标题
    WindowTitle{
        width: parent.width
        height: 50
    }
    // 关于
    About{
        id:about
    }

    LoginHome{

    }
}
