import QtQuick 2.12
import QtQuick.Controls 2.12
import Qt.labs.platform 1.1
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3

import Toou2D 1.0

import "qrc:/qml/NotificationPanel"
import "qrc:/qml"

// 通知面板

Item {
    objectName: "itemNotificationPanelHomeObject"
    id:itemNotificationPanelHome

    // 背景颜色
    Rectangle{
        width: parent.width
        height: parent.height
        color: "#ECF5FF"
    }


        T2DWorld{
            mouseAreaCursorShape: Qt.PointingHandCursor
            appStartupTheme: "Dark"
        }

    // 菜单高度
    property int menuHeight:50
    // 头部区域高度
    property int notificationPanelHomeHeaderHeight: 100

    Column{
        width: parent.width
        height: parent.height

        NotificationPanelHomeTitle{
            id:notificationPanelHomeTitle
            width: parent.width
            height: menuHeight
        }

        NotificationPanelHomeHeader{
            id:notificationPanelHomeHeader
            width: parent.width
            height: notificationPanelHomeHeaderHeight
        }

        StackView{
            id:stackViewNotificationPannelHome
            width: parent.width
            height: parent.height-notificationPanelHomeHeaderHeight-menuHeight
            visible: true
            //默认显示
            initialItem:"qrc:/qml/NotificationPanel/NotificationPanelHomeContent.qml"
        }
    }

    About{
        id:aboutNotificationHome
        onTriggered: {
            hideAndClose();
        }
    }
}



