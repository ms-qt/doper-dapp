import QtQuick 2.0
import Toou2D 1.0



Item {

    width: parent.width
    height: parent.height


    // 头像
    Image {
        id:imageMainHomeAvatar
        width: 100
        height: 100
        scale: 0.8
        source: "qrc:/images/image_default.png"
    }

    MainHomeLeftMenu{
        anchors.top: imageMainHomeAvatar.bottom
        anchors.bottom:imageMainHomePluginManager.top
        width: 100
        height: parent.height-imageMainHomeAvatar.height-imageMainHomePluginManager.height
        id:mainHomeLeftMenu
    }

    // 插件管理
    Image {
        anchors.bottom:parent.bottom
        id:imageMainHomePluginManager
        width: 100
        height: 100
        scale: 0.8
        source: "qrc:/images/image_plugin.png"
    }


    property int  menuPosition : 0


    TRectangle{
        visible:menuPosition==0
        anchors.left: imageMainHomeAvatar.right
        color: "#f0f0f0"
        width: parent.width-100
        height: parent.height
    }

    TRectangle{
        visible:menuPosition==1
        anchors.left: imageMainHomeAvatar.right
        color: "#aaa000"
        width: parent.width-100
        height: parent.height
    }

    TRectangle{
        visible:menuPosition==2
        anchors.left: imageMainHomeAvatar.right
        color: "#aa00ff"
        width: parent.width-100
        height: parent.height
    }


    Connections{
        target: mainHomeLeftMenu
        onMenuCurrent:{
            console.log(position)
            menuPosition=position
        }
    }
}
