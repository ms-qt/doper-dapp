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

    id:mainWindow

    visible: true
    width: Screen.width/6*5
    height: Screen.height/6*5

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
            mainWindow.x = mainWindow.x + (mouse.x - xMouse)
            mainWindow.y = mainWindow.y + (mouse.y - yMouse)
        }
    }

    flags: Qt.Window | Qt.FramelessWindowHint

    function doMinimized() {
        flags = Qt.Window | Qt.WindowFullscreenButtonHint | Qt.CustomizeWindowHint | Qt.WindowMinimizeButtonHint
        visibility = Window.Minimized
    }
    onVisibilityChanged: {
        if (Window.Minimized !== visibility) {
            flags = Qt.Window | Qt.FramelessWindowHint
        }
    }




    // 加载中
    BaseLoading{
        visible: false
        objectName: "baseLoadingObject"
        id:baseLoadingMainWindow
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


    // 关于
    About{
        id:aboutMainWindow
    }


    TPopoverMenu{
        id:themePopoverMainWindow;

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



    MainHome{
        anchors.top: mainWindowTitle.bottom
        width: parent.width
        height: parent.height-mainWindowTitle.height
    }

    // 标题
    MainWindowTitle{
        id:mainWindowTitle
        width: parent.width
        height:rootWindow.global.windowTitleHeight
    }


}
