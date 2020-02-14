import QtQuick 2.0
import QtGraphicalEffects 1.0

import "qrc:/qml/Base"
import "qrc:/qml/Base/Button"

Rectangle {

    width: parent.width
    height: parent.height

    property string name
    property int age
    property bool sex
    property string signature
    property string avatar
    property string qq
    property string email
    property string jobtitle
    property string department
    property string phonenumber


    property color backgroundColor: "#EBEDEE"
    property color separatorColor: "#DDE0DF"
    property color offlineColor: "#FF645F"
    property color onlineColor: "#5ABE50"
    property color presenceTextColor: "#5B5B5B"



    Item{
        width: parent.width
        height: parent.height

        Item {
            id: itemAddressBookItemAvatar
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            anchors.leftMargin: 12
            height: parent.height - 14
            width: height

            Image {
                id: imageAvatar
                width: parent.width
                height: parent.height
                sourceSize: Qt.size(parent.width, parent.height)
                smooth: true
                visible: false
                asynchronous: true
                source: "image://async/"+avatar
            }

            Rectangle {
                id: rectangleMask

                width: parent.width
                height: parent.height
                radius: parent.height/2
                smooth: true
                visible: false
            }

            OpacityMask {
                anchors.fill: imageAvatar
                source: imageAvatar
                maskSource: rectangleMask
            }
        }


        Rectangle{
            anchors.left: itemAddressBookItemAvatar.right
            color: "transparent"
            anchors.leftMargin: 10
            width: parent.height
            height: parent.height
            Column{
                Text {
                    text: qsTr(name)
                    font.pixelSize: 20
                    font.bold: true
                    font.family: "微软雅黑"
                }

                Text {
                    text: qsTr(phonenumber)
                    font.pixelSize: 15
                    font.bold: true
                    font.family: "微软雅黑"
                }
            }
        }
    }

    // 分割线
    Rectangle {
        id: separatorLine
        width: parent.width
        height: 1
        color: separatorColor
        anchors.bottom: parent.bottom
    }
}

