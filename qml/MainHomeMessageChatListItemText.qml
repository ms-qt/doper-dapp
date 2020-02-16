import QtQuick 2.0

Rectangle {

    property string textContent
    property string sender
    property bool me
    property int time

    color: "#0011aa"

    Text {
        id:textMainHomeMessageChatListItemTextContent
        anchors.centerIn: parent
        text: qsTr(textContent)
        font.pixelSize: 20
        color: "#ffffff"
    }
}
