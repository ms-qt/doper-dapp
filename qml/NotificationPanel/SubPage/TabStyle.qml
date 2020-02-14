import QtQuick 2.1
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

TabViewStyle {
    property real tabRadius
    tabsAlignment: Qt.AlignHCenter
    tabBar: Rectangle {
        color: "white"
    }
    tabOverlap: 4
    tab: Rectangle {
        property color tabColorOn: "#515151"
        property color tabColorOff: "#F0F0F0"

        color: styleData.selected ? tabColorOn : tabColorOff
        implicitWidth: Math.max(textMainTabStyle.width + 4, 100)
        implicitHeight: 40
        radius: tabRadius
        Text {
            id: textMainTabStyle
            anchors.centerIn: parent
            text: styleData.title
            font.pixelSize: 20
            color: styleData.selected ? parent.tabColorOff : parent.tabColorOn
        }
    }
}
