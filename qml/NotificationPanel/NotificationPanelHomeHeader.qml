import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.1
import QtQuick.Controls.Material 2.3

// 通知面板头部
Rectangle{
    width: parent.width
    height: parent.height
    id:rectangleNotificationPanelHomeHeader

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

                    source:"image://async/"+userModel.getAvatar(certificateBean.user_id)
                    anchors.centerIn: parent
                }

                //头像处修改转态
//                Image {
//                    id: image
//                    source: "qrc:/images/img_buddy.png"
//                    anchors.centerIn: parent
//                    MouseArea{
//                        id: mouseArea
//                        anchors.fill: parent;
//                        acceptedButtons: Qt.LeftButton | Qt.RightButton
//                        onClicked:{
//                            if (mouse.button === Qt.LeftButton) {
//                                window.visible = true
//                                menu.open();
//                            }
//                            if (mouse.button === Qt.RightButton) {
//                                window.visible = false
//                            }
//                        }
//                    }
//                }
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
                text: qsTr(userModel.getName(certificateBean.user_id))
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
                signatureText:userModel.getSignature(certificateBean.user_id)==""?"点击修改签名":userModel.getSignature(certificateBean.user_id)
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
