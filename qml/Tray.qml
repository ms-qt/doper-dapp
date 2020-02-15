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
        MenuSeparator{
        }
        MenuItem {
            text: qsTr("在线")
            onTriggered: {
                Qt.quit()
            }
        }
        MenuItem {
            text: qsTr("离线")
            onTriggered: {
                Qt.quit()
            }
        }
        MenuItem {
            text: qsTr("离开")
            onTriggered: {
                Qt.quit()
            }
        }
        MenuItem {
            text: qsTr("忙碌")
            onTriggered: {
                Qt.quit()
            }
        }
        MenuItem {
            text: qsTr("隐身")
            onTriggered: {
                Qt.quit()
            }
        }

        MenuSeparator{
        }

        MenuItem {
            text: qsTr("打开导航面板")
            onTriggered: {
                Qt.quit()
            }
        }

        MenuItem {
            text: qsTr("打开主控面板")
            onTriggered: {
                Qt.quit()
            }
        }

    }
}
