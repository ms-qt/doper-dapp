import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.1
import QtQuick.Controls.Material 2.3

import UserModel 1.0



// 通知面板头部
Rectangle{
    width: parent.width
    height: parent.height
    id:rectangleNotificationPanelHomeHeader

    UserModel{
        id:userModelNotificationHomeHeader
    }

    Row{
        width: parent.width
        height: parent.height-1

        Item{
            id:itemNotificationPanelHomeHeaderAvatar
            width: parent.height
            height: parent.height
            Rectangle{

                anchors.leftMargin: 10
                width: parent.height
                height: parent.height
                anchors.centerIn: parent
                Image{
                    id:imageNotificationPanelHomeHeaderAvatar
                    width: parent.height/2
                    height: parent.height/2

                    source:"image://imageAsync/"+userModelNotificationHomeHeader.getUserByUserId(rootWindow.global.userid)._avatar
                    anchors.centerIn: parent
                }
            }
        }

        Item{
            id:itemNotificationPanelHomeHeaderName
            width: parent.width-imageNotificationPanelHomeHeaderAvatar.width
            height: parent.height
            Text {
                id:textNotificationPanelHomeHeaderName
                topPadding: 10
                anchors.leftMargin: 20
                anchors.topMargin: 20
                text: qsTr(userModelNotificationHomeHeader.getUserByUserId(rootWindow.global.userid)._name)
                font.pixelSize: 25
                font.bold: true
                font.family: "Microsoft YaHei Mono"
            }

            Signature{
                width: parent.width
                height: 30
                anchors.top: textNotificationPanelHomeHeaderName.bottom
                anchors.leftMargin: 20
                anchors.topMargin: 20

                signatureText:userModelNotificationHomeHeader.getUserByUserId(rootWindow.global.userid)._signature==""?"点击修改签名":userModelNotificationHomeHeader.getUserByUserId(rootWindow.global.userid)._signature
            }
        }
    }

    // 分割线
    Rectangle{
        anchors.bottom: parent.bottom
        width: parent.width
        height: 1
        color: "#333333"
    }
}
