import QtQuick 2.0
import QtQuick.Layouts 1.0
import Toou2D 1.0

import EmojiModel 1.0

Item {
    width: parent.width
    height: parent.height

    function setRoomId(roomid)
    {
        mainHomeMessageChatList.setRoomId(roomid)
    }

    property int rightComponentWidth : 200

    Rectangle{
        id:rectangleMainHomeMessageChatTopMenu
        width: parent.width-rightComponentWidth
        height: 60
        color: "#ff0011"
    }

    // 聊天信息列表
    MainHomeMessageChatList{
        id:mainHomeMessageChatList
        anchors.top:rectangleMainHomeMessageChatTopMenu.bottom
        width: parent.width-rightComponentWidth
        height: parent.height-160
    }

    property int menuIconSize  : 25

    // 输入框
    Rectangle{
        id:rectangleMainHomeMessageChatBottom
        anchors.top:mainHomeMessageChatList.bottom
        width: parent.width-rightComponentWidth
        height: 100
        color: "#f055aa"

        TRectangle{
            width: parent.width
            height: 30

            Row{
                width: parent.width
                height: parent.height


                TRectangle{
                    width: menuIconSize
                    height: menuIconSize
                    TImage{
                        anchors.centerIn: parent
                        width: menuIconSize
                        height: menuIconSize
                        source: "qrc:/images/image_emoji.png"
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.leftMargin: 15
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            rectangleEmoji.visible=!rectangleEmoji.visible
                        }
                    }
                }

                TRectangle{
                    width: menuIconSize
                    height: menuIconSize

                    TImage{
                        anchors.centerIn: parent
                        width: menuIconSize
                        height: menuIconSize
                        source: "qrc:/images/image_file.png"
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
                TRectangle{
                    width: menuIconSize
                    height: menuIconSize
                    TImage{
                        anchors.centerIn: parent
                        width: menuIconSize
                        height: menuIconSize
                        source: "qrc:/images/image_video.png"
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
                TRectangle{
                    width: menuIconSize
                    height: menuIconSize
                    TImage{
                        anchors.centerIn: parent
                        width: menuIconSize
                        height: menuIconSize
                        source: "qrc:/images/image_voice.png"
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
            }
        }
    }

    Rectangle{
        id:rectangleEmoji
        width: rectangleMainHomeMessageChatBottom.width/3*2
        height: 300
        color: "#ffffff"
        anchors.left: parent.left
        anchors.bottom: rectangleMainHomeMessageChatBottom.top
        visible: false
        EmojiPicker {
            width: rectangleEmoji.width
            height: parent.height
            anchors.centerIn: parent
            Layout.fillWidth: true
            id: emojiPicker
            visible: true
            textArea: textAreaMessage
            emojiModel: EmojiModel { id: emojiModel }
        }
    }
}
