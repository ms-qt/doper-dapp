import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12

import Toou2D 1.0

ApplicationWindow {

    id:rootWindow
    property int rootWindowWidth : 320
    property int rootWindowHeight : 480


    T2DWorld{
        appStartupTheme: "Solarized"
        appThemePaths: [
            "qrc:/themes/"
        ]

        mouseAreaCursorShape: Qt.PointingHandCursor
    }




}
