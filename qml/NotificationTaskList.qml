import QtQuick 2.0
import QtGraphicalEffects 1.0


Rectangle {
    id: rectangleTaskListRoot
    property color background: "#EBEDEE"
    property color highlightHover: "#DDE0DF"
    property color highlightSelection: "#8D8E8E"

    color: background
    clip: true

    ListView {
        id: listViewTaskList
        anchors.fill: parent
        anchors.topMargin: 5

        opacity: 1
        boundsBehavior: Flickable.DragAndOvershootBounds
        maximumFlickVelocity: 2500
        snapMode: ListView.SnapToItem

        model:taskListModel
        delegate: NotificationTaskListItem {
            taskName: taskModel.getTaskName(_task_id+"")

            width: listViewTaskList.width
            height: 85

            color: listViewTaskList.currentIndex === index ? "transparent" : (mouseAreaTaskList.containsMouse ? highlightHover : background)
            backgroundColor: listViewTaskList.currentIndex === index ? "transparent" : (mouseAreaTaskList.containsMouse ? highlightHover : background)
            separatorColor: listViewTaskList.currentIndex === index ? "transparent" : highlightHover
            smooth: mouseAreaTaskList.containsMouse


            MouseArea {
                id: mouseAreaTaskList
                anchors.left: parent.left
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    listViewTaskList.currentIndex = index
                }

                onDoubleClicked: {
                    taskListModel.enterTask(_task_id)
                }
            }
        }

        highlight:
            Rectangle {
            color: highlightSelection
            radius: 3
            anchors.fill: listViewTaskList.currentItem
        }
        highlightFollowsCurrentItem: true
        highlightRangeMode: ListView.NoHighlightRange
    }
}
