import QtQuick 2.0

Item {

    width: parent.width
    height: parent.height

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
    }

    Image {
        anchors.bottom:parent.bottom
        id:imageMainHomePluginManager
        width: 100
        height: 100
        scale: 0.8
        source: "qrc:/images/image_plugin.png"
    }
}
