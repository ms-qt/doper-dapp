import QtQuick 2.12
import QtQuick.Controls 2.12
import Qt.labs.platform 1.1
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick 2.0
import QtGraphicalEffects 1.0

Item{

    property int iconwidth: 35
    property int iconheight: 35
    property int fontSize: 18


    anchors.horizontalCenter: parent.horizontalCenter
    width: 100
    height: 100
    Column{
        Layout.margins: 30
        anchors.centerIn: parent
        Image {

            width: iconwidth
            height: iconheight
            anchors.margins: 10
            anchors.horizontalCenter: parent.horizontalCenter
            source: model.iconUrl
        }
        Text{
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr(model.name)
            font: font.pixelSize=fontSize
        }
    }
}

