import QtQuick 2.12
import QtQuick.Controls 2.12
import Qt.labs.platform 1.1
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3

import "qrc:/qml/NotificationPanel/SubPage"

// 通知面板内容

Item{
    width: stackViewNotificationPannelHome.width
    height: stackViewNotificationPannelHome.height

    // 切换卡片
    SwipeView {
        id:swipeViewNotificationPanelHomeContent
        width: parent.width
        height: parent.height
        anchors.centerIn: parent
        onCurrentIndexChanged: {
            console.log(currentIndex)
            switch(currentIndex){
            case 0:
                tabBarFoot.setCurrentIndex(0)
                break
            case 1:
                tabBarFoot.setCurrentIndex(1)
                break
            case 2:
                tabBarFoot.setCurrentIndex(2)
                break;
            }
        }

        AddressBook{
            width:stackViewNotificationPannelHome.width
            height:stackViewNotificationPannelHome.height

        }
        Message{
            width:stackViewNotificationPannelHome.width
            height:stackViewNotificationPannelHome.height
        }
        Task{
            width:stackViewNotificationPannelHome.width
            height:stackViewNotificationPannelHome.height
        }
    }

    // 底部导航

    TabBar {
        id:tabBarFoot
        width: parent.width

        anchors.bottom: parent.bottom
        TabButton {
            text: qsTr("通讯录")
            height: parent.height
            font.pointSize: 20
            font.bold: true
            onClicked: {
                swipeViewNotificationPanelHomeContent.setCurrentIndex(0)
            }
        }
        TabButton {
            text: qsTr("消息")
            height: parent.height
            font.pointSize: 20
            font.bold: true
            onClicked: {
                swipeViewNotificationPanelHomeContent.setCurrentIndex(1)
            }
        }
        TabButton {
            text: qsTr("任务")
            height: parent.height
            font.pointSize: 20
            font.bold: true
            onClicked: {
                swipeViewNotificationPanelHomeContent.setCurrentIndex(2)
            }
        }
    }
}
