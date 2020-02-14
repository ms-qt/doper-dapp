import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.3
import Tools 1.0
import "../BasicComponent"
import "../BizComponent"
import TreeModel 1.0

Rectangle {
    id: explorerWindow
    visible: true
    width: parent.width
    height: parent.height
    color: config.mainColor
	property string json :'[{"name":"平台管理","subType":[{"name":"魏爱辉"},{"name":"王志明"},{"name":"王晓波"},{"name":"李诗琦"},{"name":"李媛"},{"name":"石亚楠"}]},{"name":"公共关系部","subType":[{"name":"王静静"},{"name":"李洋萱"},{"name":"吴婧宇"}]},{"name":"北斗数睿","subType":[{"name":"产品研发部","subType":[{"name":"李卫宁"},{"name":"方士琦"},{"name":"汪浩琰"},{"name":"雷行京"},{"name":"罗大伟"},{"name":"张赛风"},{"name":"杨琦"}]},{"name":"市场合作部","subType":[{"name":"姜世杰"}]}]},{"name":"北斗智联慧车","subType":[{"name":"产品研发部","subType":[{"name":"孙爱超"},{"name":"蒋帅"},{"name":"李伟"}]},{"name":"市场合作部","subType":[{"name":"石磊"}]}]},{"name":"研发部","subType":[{"name":"陈春海"},{"name":"梁家振"},{"name":"隋明君"},{"name":"毛华伟"},{"name":"张宁"}]}]'
    Component.onCompleted: {
//        tModel.loadFromJsonString(json)
		tModel.loadFromName();
        tModel.collapseAll()
    }

    TConfig {
        id: config
    }
    TDialog {
        id: fileDialog
    }
    TMessageBox {
        id: messageBox
    }
    Connections {
        target: tModel
        onShowMessage:{
            messageBox.showMessage("提示", message)
        }
    }

    Conversation{
        id:mainConversationView
        anchors.left: tView.right
        anchors.right: explorerWindow.right
        height: parent.height
        inConversationWith: tView.currentData.name
    }

//    Conversation {
//        id:childConversationView
//        anchors.left: mainConversationView.right
//        width: (explorerWindow.width - TTreeHeader.width)/2
//        height: parent.height
//        model: childConversation.timeLine
//        name:"child"
//    }


    TreeModel {
        id: tModel
    }
    TTreeHeader {
        id: treeHeader
        width: 300
        height: 70
        treeModel: tModel
        treeView: tView
    }
    TTreeView {
        id: tView
        width: treeHeader.width
        anchors {
            top: treeHeader.bottom
            bottom: parent.bottom
        }
        sourceModel: tModel
        onExpand: {
            tModel.expand(index)
        }
        onCollapse: {
            tModel.collapse(index)
        }
    }
//    TPropHeader {
//        id: propHeader
//        width: 300
//        height: 70
//        treeModel: tModel
//        propView: propertiesView
//        anchors {
//            right: parent.right
//        }
//    }
//    TPropView {
//        id: propertiesView
//        width: propHeader.width
//        nameWidth: propHeader.nameWidth
//        typeWidth: propHeader.typeWidth
//        valueWidth: propHeader.valueWidth
//        dataSource: tView.currentData
//        anchors {
//            right: parent.right
//            top: propHeader.bottom
//            topMargin: 1
//            bottom: parent.bottom
//        }
//    }
}
