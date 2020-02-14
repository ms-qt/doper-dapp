import QtQuick 2.12
import QtQuick.Controls 2.12
import Qt.labs.platform 1.1
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick 2.0
import QtGraphicalEffects 1.0

import "qrc:/qml/MainControlPanel"

// 左侧菜单
Rectangle {

    id:rectangleMenuList

    width: parent.width
    height: parent.height

    color: "#999999"

    ListView{
        id:listViewHomeLeftMenu
        width: parent.width
        height: parent.height
        model: homeLeftMenuModel
        spacing: 15
        cacheBuffer: 10
        focus: true
        clip: true
        boundsBehavior:ListView.SnapToItem
        Layout.margins: 10

        highlightFollowsCurrentItem: false
        anchors {
            fill: parent
        }
        highlight: Component {
            id: componentHomeLeftMenuListViewhighlightBar
            Rectangle {
                width: 100
                height: 100
                color: "#676767"
                y: listViewHomeLeftMenu.currentItem.y;
                Behavior on y { SpringAnimation { spring: 1; damping:0.2 } }
            }
        }
        delegate:MenuListItem{

            states: State {
                name: "Current"
                when: listViewHomeLeftMenu.isCurrentItem
                PropertyChanges {
                    target: content
                    x: 20
                }
            }

            transitions: Transition {
                NumberAnimation { properties: "x"; duration: 200 }
            }
            MouseArea{
                onClicked: {
                    listViewHomeLeftMenu.currentIndex = index
                    if(!listViewHomeLeftMenu.activeFocus){
                        listViewHomeLeftMenu.forceActiveFocus();
                    }
                    switch(index){

                    }
                }
            }
        }
    }
}
