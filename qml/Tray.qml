import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12

import QtQuick 2.12
import QtQuick.Window 2.12

import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4

import QtQuick.Controls.Material 2.12
import Qt.labs.platform 1.1
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3

SystemTrayIcon {
    visible: true
    icon.source: "qrc:/images/img_icon_blue.png"
    tooltip: "北斗IM"


    menu: Menu {
        MenuItem {
            text: qsTr("退出")
            onTriggered: {
                Qt.quit()
            }
        }

        MenuItem {
            visible: false
            text: qsTr("在线")
            onTriggered: {
                Qt.quit()
            }
        }
    }
}
