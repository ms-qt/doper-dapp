import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import MessageListModel 1.0
import MessageTextModel 1.0


import Toou2D 1.0

// 聊天信息的列表
Item {
    width: parent.width
    height: parent.height


    MessageListModel{
        id:messageListModelContent
    }

    MessageTextModel{
        id:messageTextModelContent
    }


    Rectangle{
        width: parent.width
        height: parent.height
        color: "#f0f00f"
    }

    function setRoomId(roomid)
    {
        messageListModelContent.filterByRoomId(roomid)
    }

    ListView {
        currentIndex: 0
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width
        height: parent.height
        id: listViewMainHomeMessageChatList
        //spacing: 1
        //verticalLayoutDirection: ListView.BottomToTop
        //boundsBehavior:ListView.SnapToItem
        cacheBuffer: 1
        focus: true
        clip: true
        ScrollBar.vertical: ScrollBar {}
        model: messageListModelContent
        delegate:Component{
            Rectangle{
                width:parent.width
                height: textMessageContent.implicitHeight+30

                TAvatar{
                    id:avatar
                    width: 30
                    height: 30
                    source: "https://dss1.bdstatic.com/70cFvXSh_Q1YnxGkpoWK1HF6hhy/it/u=1915011011,2156126360&fm=26&gp=0.jpg"
                    radius: 20;
                }

                TLabel{
                    anchors.left: avatar.right
                    anchors.leftMargin: 10
                    text:   Qt.formatDateTime(new Date(_time), "hh:mm")
                    font.pixelSize: 10
                    color: "#000000"
                    id:labelTime
                }

                Rectangle{
                    anchors.left: avatar.right
                    anchors.top:labelTime.bottom
                    anchors.topMargin: 5
                    anchors.leftMargin: 5
                    width:textMessageContent.implicitWidth+10
                    height: textMessageContent.implicitHeight+10
                    color: "#E6E6FA"
                    radius: 10;
                    Text {
                        anchors.centerIn: parent
                        id: textMessageContent
                        text: messageTextModelContent.textContentByMessageId(_message_id)
                        color: "#000000"
                        wrapMode: Text.Wrap
                        font : font.pixelSize=15
                    }
                }
            }
        }
        //            MainHomeMessageChatListItem{
        //            messageType : _message_type
        //            messageId:_message_id
        //            time : _time
        //        }
    }
}
