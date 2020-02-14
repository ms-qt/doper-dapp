import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import Qt.labs.platform 1.1
import QtQuick.Layouts 1.13
import "../appcomponent"
import "qrc:/qml/Login"
import "qrc:/qml/Base"
import "qrc:/qml/NotificationPanel"
import "qrc:/qml/MainControlPanel/IM"

Item{
    id:itemMainRoot
    visible: true
    width: Screen.width/6*5
    height: Screen.height/6*5
    property bool loginStatus: true


    // titile 高度
    property int  titleHeight: 50
    // title
    MainPanelTitle{
        id:mainPanelTitle
        width: parent.width
        height: titleHeight
    }

    // 左侧菜单宽度
    property int  leftMenuSideBarWidth: 100

    // 左侧菜单
    LeftMenuSideBar{
        id:leftMenuSideBarMain
        anchors.top: mainPanelTitle.bottom
        visible: loginStatus
        width: leftMenuSideBarWidth
        height: itemMainRoot.height-titleHeight
    }


    Rectangle {
        anchors.top: mainPanelTitle.bottom
        visible: loginStatus
        id: view
        anchors.left: leftMenuSideBarMain.right
        anchors.leftMargin: 0
        width: parent.width-leftMenuSideBarWidth
        height: parent.height-titleHeight

        Rectangle{
            width: parent.width
            height: parent.height
            visible: leftMenuSideBarMain.currentIndex == 1

            //            ExplorerView {
            //                width: 260
            //                height: parent.height
            //                id:explorerViewMain
            //            }

            RoomList{
                width: parent.width
                height: parent.height
            }
        }

        Rectangle{
            visible: leftMenuSideBarMain.currentIndex == 4
            Task{
                id:mytask
            }
        }
        Rectangle{
            visible: leftMenuSideBarMain.currentIndex == 2
            Plugin{
                id:plugin
            }
        }
        Rectangle{
            visible: leftMenuSideBarMain.currentIndex == 3
            Inform {
                width: itemMainRoot.width- leftMenuSideBarMain.width
                height: itemMainRoot.height
                id :myinform
            }
        }
    }
}
