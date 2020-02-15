import QtQuick 2.12
import QtQuick.Controls 2.12
import Qt.labs.platform 1.1
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3


// 通知面板内容

Item{
    width: parent.width
    height: parent.height

    // 切换卡片
    SwipeView {
        id:swipeViewNotificationHomeContent
        width: parent.width
        height: parent.height-tabBarFoot.height
        anchors.bottom: tabBarFoot.top
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

//        NotificationAddressBook{
//            width:parent.width
//            height:parent.height

//        }
//        NotificationMessage{
//            width:parent.width
//            height:parent.height
//        }

        NotificationTask{
            width:parent.width
            height:parent.height
        }
    }

    // 底部导航

    TabBar {
        id:tabBarFoot
        width: parent.width
        height: 50
        anchors.bottom: parent.bottom
        TabButton {
            text: qsTr("通讯录")
            height: parent.height
            font.pointSize: 20
            font.bold: true
            onClicked: {
                swipeViewNotificationHomeContent.setCurrentIndex(0)
            }
        }
        TabButton {
            text: qsTr("消息")
            height: parent.height
            font.pointSize: 20
            font.bold: true
            onClicked: {
                swipeViewNotificationHomeContent.setCurrentIndex(1)
            }
        }
        TabButton {
            text: qsTr("任务")
            height: parent.height
            font.pointSize: 20
            font.bold: true
            onClicked: {
                swipeViewNotificationHomeContent.setCurrentIndex(2)
            }
        }
    }
}
