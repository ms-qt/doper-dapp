import QtQuick 2.12
import QtQuick.Controls 2.12
import Qt.labs.platform 1.1
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import Toou2D 1.0




// 通知面板
Item {
    objectName: "itemNotificationPanelHomeObject"
    id:itemNotificationHome

    // 背景颜色
    Rectangle{
        width: parent.width
        height: parent.height
        color: "#ECF5FF"
    }



    // 头部区域高度
    property int notificationHomeHeaderHeight: 100

    Item{
        width: parent.width
        height: parent.height

        NotificationHomeHeader{
            id:notificationHomeHeader
            width: parent.width
            height: notificationHomeHeaderHeight
        }

        StackView{
            anchors.top: notificationHomeHeader.bottom
            id:stackViewNotificationHome
            width: parent.width
            height: parent.height-notificationHomeHeader.height
            visible: true
            //默认显示
            initialItem:"qrc:/qml/NotificationHomeContent.qml"
        }
    }
}



