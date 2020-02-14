import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import Gaga 1.0
Item {
    id: element1
    width: 800
    height: 600


    ListModel {
         id:roomList
         ListElement {
             roomHeader : "qrc:/header.jpg"
             roomName : "毛华伟"
             roomTime : "昨天"
             roomMsg : "搞得怎么样了"

         }
         ListElement {
             roomHeader : "qrc:/header.jpg"
             roomName : "研发部"
             roomTime : "8:00"
             roomMsg : "新技术"
         }
         ListElement {
             roomHeader : "qrc:/header.jpg"
             roomName : "梁家振"
             roomTime : "前天"
             roomMsg : "搞得怎么样了"
         }
     }

    ListModel {
         id:roomMsg
         ListElement {
             userHeader : "qrc:/header.jpg"
             userMsg : "搞得怎么样了"
             isMe: false
         }
         ListElement {
             userHeader : "qrc:/header.jpg"
             userMsg : "今天是一个大晴天"
             isMe: true
         }
         ListElement {
             userHeader : "qrc:/header.jpg"
             userMsg : "小明今天没来上班"
             isMe: false
         }
     }



    Rectangle {
        id:roomListView
        width: 200; height: 600
        Component {
            id: contactDelegate
            Item {
                id: element
                Image {
                    id: header
                    width: 50
                    anchors.top: parent.top
                    anchors.topMargin: 5
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 5
                    anchors.left: parent.left
                    anchors.leftMargin: 5
                    source: roomHeader
                }
                width: 200; height: 50
                Text { id: name; text: roomName ; anchors.top: parent.top; anchors.topMargin: 5; anchors.left: header.right;anchors.leftMargin: 10 }
                Text { id: time; x: 148; text: roomTime ; anchors.top: parent.top; anchors.topMargin: 5; anchors.right: parent.right;anchors.rightMargin: 5 }
                Text { id: msg; y: 28; text: roomMsg ; anchors.left: header.right; anchors.leftMargin: 5; anchors.bottom: parent.bottom; anchors.bottomMargin: 5 }

            }

        }

        ListView {
            anchors.fill: parent
            model: roomList
            delegate: contactDelegate
            highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
            focus: true
        }
    }

    Rectangle {
        id:roomMsgView
        width: 600; height: 600
        color: "#d46b6b"
        anchors.left: roomListView.right
        anchors.leftMargin: 0
        Component {
            id: userMsgComponent
            Item {
                id: userMsgItem
                Image {
                    id: userHeaderImg
                    width: 50
                    anchors.top: parent.top
                    anchors.topMargin: 5
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 5
                    anchors.left: parent.left
                    anchors.leftMargin: 5
                    source: modelHeader
                }
                 height: 50

                Text { id: roomMsgText; y: 28; text: modelMsg ; anchors.left: userHeaderImg.right; anchors.leftMargin: 5; anchors.bottom: parent.bottom; anchors.bottomMargin: 5 }

            }
        }

        Component {
            id: myMsgComponent
            Item {
                id: myMsgItem
                Image {
                    id: myHeaderImg
                    width: 50
                    anchors.top: parent.top
                    anchors.topMargin: 5
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 5
                    anchors.left: parent.left
                    anchors.leftMargin: 5
                    source: modelHeader
                }
                width: parent.width
                height: 50

                Text { id: myMsgText; y: 28; text: modelMsg ; anchors.right: myHeaderImg.left; anchors.rightMargin: 5; anchors.bottom: parent.bottom; anchors.bottomMargin: 5 }

            }
        }


        ListView {
            anchors.fill: parent
            model: roomMsg
            delegate:Component {
                id: delegateComponent
                Loader {
                    property string modelHeader: userHeader
                    property string modelMsg: userMsg
                    property bool modelMe: isMe
                    sourceComponent: {
//                        if(modelMe == true)
//                        {
                            return myMsgComponent
//                        }
//                        else
//                        {
//                            return userMsgComponent
//                        }
                    }
                }
            }
            highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
        }
    }
}



