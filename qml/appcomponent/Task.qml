

import QtQuick 2.0
import QtWebEngine 1.7
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11


Item  {
    anchors.fill: parent
    visible: true
    WebEngineView {
       anchors.fill: parent
       url: "https://mdn.github.io/sw-test/"
	   //url:"https://www.baidu.com"
       settings.javascriptEnabled: true
    }
}
