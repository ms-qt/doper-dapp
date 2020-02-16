import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import MessageListModel 1.0


import Toou2D 1.0

// 聊天信息的列表
Item {
    width: parent.width
    height: parent.height


    MessageListModel{
        id:messageListModelContent
    }

    Rectangle{
        width: parent.width
        height: parent.height
        color: "#f0f00f"
    }

    function setRoomId(roomid)
    {
        messageListModelContent.filterByRoomId(roomid)
        listViewMainHomeMessageChatList.currentIndex=0
    }

    ListView {
        currentIndex: 0
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width
        height: parent.height
        id: listViewMainHomeMessageChatList
        spacing: 5
        //        verticalLayoutDirection: ListView.BottomToTop
        //        boundsBehavior:ListView.SnapToItem
        cacheBuffer: 1
        focus: true
        clip: true
        ScrollBar.vertical: ScrollBar {}
        model: messageListModelContent
        delegate:Component{



            Rectangle{
                width:parent.width
                height: messageText.implicitHeight+30

                TAvatar{
                    id:vaatar
                    width: 50
                    height: 50
                    source: "https://dss1.bdstatic.com/70cFvXSh_Q1YnxGkpoWK1HF6hhy/it/u=1915011011,2156126360&fm=26&gp=0.jpg"
                }

                Rectangle{
                    anchors.left: vaatar.right
                    width:parent.width
                    height: messageText.implicitHeight+30
                    color: "#ff0a00"


                    Text {
                        width:parent.width
                        id: messageText
                        text: "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"
                        color: "#ffffff"
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
