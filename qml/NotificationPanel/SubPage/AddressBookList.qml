import QtQuick 2.0
import QtGraphicalEffects 1.0

import "qrc:/qml/Base"
import "qrc:/qml/Base/Button"

Rectangle {
    property color background: "#EBEDEE"
    property color highlightHover: "#DDE0DF"
    property color highlightSelection: "#8D8E8E"
    color: background
    clip: true

    ListView {
        id: listViewAddressBookList
        anchors.fill: parent
        anchors.topMargin: 5
        opacity: 1
        boundsBehavior: Flickable.DragAndOvershootBounds
        maximumFlickVelocity: 2500
        snapMode: ListView.SnapToItem

        model:  userModel
        delegate: AddressBookItem {
            name:_name
            avatar: _avatar
            phonenumber: _phonenumber
            width: listViewAddressBookList.width
            height: 85
            color: listViewAddressBookList.currentIndex === index ? "transparent" : (mouseAreaAddressBookList.containsMouse ? highlightHover : background)
            backgroundColor: listViewAddressBookList.currentIndex === index ? "transparent" : (mouseAreaAddressBookList.containsMouse ? highlightHover : background)
            separatorColor: listViewAddressBookList.currentIndex === index ? "transparent" : highlightHover
            smooth: mouseAreaAddressBookList.containsMouse

            MouseArea {
                id: mouseAreaAddressBookList
                anchors.left: parent.left
                anchors.fill: parent
                hoverEnabled: true
                acceptedButtons: Qt.LeftButton | Qt.RightButton // 激活右键（别落下这个）
                onClicked: {
                    listViewAddressBookList.currentIndex = index
                    if (mouse.button == Qt.RightButton) { // 右键菜单
                        //
                        // 鼠标按下的 x y 坐标
                        console.log("x : "+mouse.x)
                        console.log("y : "+mouse.y)

                        // 赋值给 启始 位置的x y 坐标
                        listMenuRight.startX= mouse.x
                        listMenuRight.startY= mouse.y

                        // 显示右键菜单
                        listMenuRight.show();
                    }
                }
                onDoubleClicked: {
                    userModel.sendMessage(_user_id)
                }
            }

            // 邮件菜单
            ListMenuRight{
                backgroundWidth: 100
                backgroundHeight: 160
                id:listMenuRight
                contentItem: ListView {
                    id: langListView
                    anchors.fill: parent
                    anchors.margins: 2
                    spacing: 4
                    clip: true
                    model: ListModel{
                        ListElement{
                            name : "查看资料"
                        }
                        ListElement{
                            name : "复制名称"
                        }
                        ListElement{
                            name : "复制电话"
                        }
                        ListElement{
                            name : "发送消息"
                        }
                    }
                    delegate: TextButton {
                        width: langListView.width
                        height: 36
                        text: modelData
                        color: containsMouse ? "lightgray" : listMenuRight.barColor
                        onClicked: {
                            // 点击之后让面板隐藏
                            listMenuRight.hide()

                            if(index==0)
                            {
                                //popupFrameInfoData.open();

                            }else if(index == 1)
                            {
                                // 复制房间ID
                                clipboard.setText(_name)
                            }else if(index == 2)
                            {
                                clipboard.setText(_phonenumber)
                            }else if(index == 3)
                            {
                                userModel.sendMessage(_user_id)
                            }
                        }
                    }
                }
            }
        }
        highlight:
            Rectangle {
            color: highlightSelection
            radius: 3
            anchors.fill: listViewAddressBookList.currentItem
        }
        highlightFollowsCurrentItem: true
        highlightRangeMode: ListView.NoHighlightRange
    }
}
