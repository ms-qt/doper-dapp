import QtQuick 2.7
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.3
Rectangle{
    width: 300
    height: 250
    ListModel {
        id:myModel
        ListElement {
            header:"qrc:/images/header.jpg"
            name: "跑来跑去的猫"
            content: "今天又是挨饿的一天"
            number:3
        }
        ListElement {
            header:"qrc:/images/header.jpg"
            name: "跑来跑去的猫"
            content: "今天又是挨饿的一天"
            number:3
        }
        ListElement {
            header:"qrc:/images/header.jpg"
            name: "跑来跑去的猫"
            content: "今天又是挨饿的一天"
            number:3
        }
        ListElement {
            header:"qrc:/images/header.jpg"
            name: "跑来跑去的猫"
            content: "今天又是挨饿的一天"
            number:3
        }
        ListElement {
            header:"qrc:/images/header.jpg"
            name: "跑来跑去的猫"
            content: "今天又是挨饿的一天"
            number:3
        }
        ListElement {
            header:"qrc:/images/header.jpg"
            name: "跑来跑去的猫"
            content: "今天又是挨饿的一天"
            number:3
        }
        ListElement {
            header:"qrc:/images/header.jpg"
            name: "跑来跑去的猫"
            content: "今天又是挨饿的一天"
            number:3
        }
    }
    Text {
        id: element
        x: 18
        y: 15
        width: 105
        height: 30
        text: qsTr("跑来跑去的猫")
        font.pixelSize: 12
    }

    Rectangle {
        width: 260; height: 149
        x:20
        y:40
        ListView {
            x: 20
            y: 40
            spacing: 10
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
            anchors.fill: parent
            model: myModel
            delegate: contactDelegate
            // highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
            focus: false
            clip: true
        }

        Component {
            id: contactDelegate
            Row {
                spacing: 30
                Image {

                    height: 30
                    width: 30
                    source: header
                }
                Column {
                    spacing: 5
                    Text {
                        text: name
                        font.weight: Font.Bold
                    }
                    Text {
                        text: content
                    }
                }
                Rectangle {
                    id: rectangle
                    x: 194
                    y: 0
                    width: 20
                    height: 20
                    color: "#c32e2e"
                    radius: 10
                    border.width: 0
                    Text {
                        anchors.centerIn: parent
                        text: number
                        color: "#ffffff"
                    }
                }

            }
        }

    }

    Rectangle {
        id: button1
        x: 180
        y: 202
        Text {
            anchors.centerIn: parent
            text: "查看全部"
            font.family: "Times New Roman"
            font.pointSize: 12
            anchors.verticalCenterOffset: 22
            anchors.horizontalCenterOffset: 32
            color: "#756fde"
        }
        color: "#ffffff"
    }

    Rectangle {
        id: button2
        x: 180
        y: 202
        color: "#ffffff"
        Text {
            width: 48
            height: 18
            anchors.centerIn: parent
            text: "忽略全部"
            font.pointSize: 12
            anchors.verticalCenterOffset: 22
            anchors.horizontalCenterOffset: -112
            color: "#756fde"
        }
    }
}
