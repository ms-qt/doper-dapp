import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Item {

    Rectangle {
        id: pluginsView
        color: "#ffffff"
        anchors.fill: parent

		 Button {
            id: pluginone
            x: 177
            y: 49
            width: 81
            height: 58
            text: qsTr("qml插件")
            z: 2
            onClicked: {
//                pluginsManager.showPlugin("qmlPlugin")
                console.log("用的qmlPLugin插件")
            }
        }
        Button {
            id: plugintwo
            x: 277
            y: 49
            width: 81
            height: 58
            text: qsTr("pwa插件")
            z: 2
            onClicked: {
//                pluginsManager.showPlugin("pwaplugin")
                console.log("用的pwaPlugin插件")
            }
        }
    }

}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
