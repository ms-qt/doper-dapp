import QtQuick 2.0
import QtQuick.Controls 2.0
import Toou2D 1.0



Item {

    width: parent.width
    height: parent.height


    property int leftMenuWidth : 100

    // 点击头像显示
    property bool avatarShow : false
    // 点击插件管理显示
    property bool managerShow : false
    // 菜单条目数
    property int  menuPosition : 0

    // 重置状态
    function resetStatus(){
        menuPosition=-1
        avatarShow=false
        managerShow=false
    }


    // 头像
    Image {
        id:imageMainHomeAvatar
        width: leftMenuWidth
        height: leftMenuWidth
        scale: 0.8
        source: "qrc:/images/image_default.png"

        MouseArea{
            anchors.fill: parent
            onClicked: {
                resetStatus()
                avatarShow=true
            }
        }
    }

    MainHomeLeftMenu{
        anchors.top: imageMainHomeAvatar.bottom
        anchors.bottom:imageMainHomePluginManager.top
        width: leftMenuWidth
        height: parent.height-imageMainHomeAvatar.height-imageMainHomePluginManager.height
        id:mainHomeLeftMenu
    }

    // 插件管理
    Image {
        anchors.bottom:parent.bottom
        id:imageMainHomePluginManager
        width: leftMenuWidth
        height: leftMenuWidth
        scale: 0.8
        source: "qrc:/images/image_plugin.png"

        MouseArea{
            anchors.fill: parent
            onClicked: {
                resetStatus()
                managerShow=true
            }
        }
    }

    // 点击头像
    TRectangle{
        visible:avatarShow
        anchors.left: imageMainHomeAvatar.right
        color: "#000000"
        width: parent.width-leftMenuWidth
        height: parent.height
    }

    // 点击插件管理
    TRectangle{
        visible:managerShow
        anchors.left: imageMainHomeAvatar.right
        color: "#001122"
        width: parent.width-leftMenuWidth
        height: parent.height
    }



    TRectangle{
        visible:menuPosition==0
        anchors.left: imageMainHomeAvatar.right
        color: "#001122"
        width: parent.width-leftMenuWidth
        height: parent.height

        MainHomeMessage{
            width: parent.width
            height: parent.height
        }
    }

    Connections{
        target: mainHomeLeftMenu
        onMenuCurrent:{
            console.log(position)
            resetStatus()
            menuPosition=position
        }
    }
}
