import QtQuick 2.0
import Toou2D 1.0

TDialog {

    bodyComponent: TRectangle{
        width:  layout.width  + 80;
        height: layout.height + 80;
        radius: 5;

        Column{
            id:layout;
            spacing: 5;
            anchors.centerIn: parent;

            TLabel{
                text: "北斗数睿运营管理平台"
                font.pixelSize: 30;
                anchors.horizontalCenter: parent.horizontalCenter;
            }

            TLabel{
                text: qsTr("版本:1.0.0-dev")
                anchors.horizontalCenter: parent.horizontalCenter;
            }
            TLabel{
                text: qsTr("作者:maohuawei,zhangning")
                anchors.horizontalCenter: parent.horizontalCenter;
            }

            Item{
                width: 10; height: 20;
            }

            TLabel{
                text: "@2019-2020"
                anchors.horizontalCenter: parent.horizontalCenter;
            }
        }
    }
}
