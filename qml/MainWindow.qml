import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3


import Toou2D 1.0

ApplicationWindow {

    id:mainWindow

    visible: true
    width: Screen.width/6*5
    height: Screen.height/6*5

    property int xMouse
    property int yMouse

    MouseArea { //为窗口添加鼠标事件
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton //只处理鼠标左键
        onPressed: { //接收鼠标按下事件
            xMouse = mouse.x
            yMouse = mouse.y
        }
        onPositionChanged: { //鼠标按下后改变位置
            mainWindow.x = mainWindow.x + (mouse.x - xMouse)
            mainWindow.y = mainWindow.y + (mouse.y - yMouse)
        }
    }

    flags: Qt.Window | Qt.FramelessWindowHint

    function doMinimized() {
        flags = Qt.Window | Qt.WindowFullscreenButtonHint | Qt.CustomizeWindowHint | Qt.WindowMinimizeButtonHint
        visibility = Window.Minimized
    }
    onVisibilityChanged: {
        if (Window.Minimized !== visibility) {
            flags = Qt.Window | Qt.FramelessWindowHint
        }
    }

    MainHome{
        anchors.top: mainWindowTitle.bottom
        width: parent.width
        height: parent.height-mainWindowTitle.height
    }

    // 标题
    MainWindowTitle{
        id:mainWindowTitle
        width: parent.width
        height:rootWindow.global.windowTitleHeight
    }


    // 加载中
    BaseLoading{
        visible: false
        objectName: "baseLoadingObject"
        id:baseLoadingMainWindow
        width: parent.width
        height: parent.height
        anchors.centerIn: parent

        Layout.margins: 10
        implicitWidth: 30
        implicitHeight: 30

        function show()
        {
            baseLoading.visible=true
        }
        function hide()
        {
            baseLoading.visible=false
        }
    }











    property var target: mainWindow;
    property point startPoint: Qt.point(0, 0);
    property point fixedPont: Qt.point(0, 0);


    /*
                 ↑     ↑     ↑
               ←|1|   |2|   |3|→
               ←|4|   |5|   |6|→
               ←|7|   |8|   |9|→
                 ↓     ↓     ↓
                分8个缩放区域
                |5|为拖动区域
           target       缩放目标
           startPoint   鼠标起始点
           fixedPont    用于固定窗口的点
           每一个area   大小 8 x 8
    */


    MouseArea
    {
        id: area1
        x: 0
        y: 0
        width: 8
        height: 8
        hoverEnabled: true

        onEntered: cursorShape = Qt.SizeFDiagCursor;
        onExited: cursorShape = Qt.ArrowCursor;
        onPressed: startPoint = Qt.point(mouseX, mouseY);
        onPositionChanged:
        {
            if(pressed)
            {
                var offsetX = mouse.x - startPoint.x;
                var offsetY = mouse.y - startPoint.y;
                if ((target.width - offsetX) >= target.minimumWidth) //如果本次调整小于最小限制，则调整为最小
                {
                    target.width -= offsetX;
                    target.x += offsetX;
                }
                else
                {
                    target.x += (target.width - target.minimumWidth);
                    target.width -= (target.width - target.minimumWidth);
                }

                if ((target.height - offsetY) >= target.minimumHeight && offsetY != 0)
                {
                    target.height -= offsetY;
                    target.y += offsetY;
                }
            }
        }
    }

    MouseArea
    {
        id: area2
        x: 8
        y: 0
        width: target.width - 16
        height: 8
        hoverEnabled: true

        onEntered: cursorShape = Qt.SizeVerCursor;
        onExited: cursorShape = Qt.ArrowCursor;
        onPressed: startPoint = Qt.point(mouseX, mouseY);
        onPositionChanged:
        {
            if(pressed)
            {
                var offsetY = mouse.y - startPoint.y;
                if ((target.height - offsetY) >= target.minimumHeight && offsetY != 0)
                {
                    target.height -= offsetY;
                    target.y += offsetY;
                }
            }
        }
    }

    MouseArea
    {
        id: area3
        x: target.width - 8
        y: 0
        width: 8
        height: 8
        hoverEnabled: true

        onEntered: cursorShape = Qt.SizeBDiagCursor;
        onExited: cursorShape = Qt.ArrowCursor
        onPressed:
        {
            startPoint = Qt.point(mouseX, mouseY);
            fixedPont = Qt.point(target.x, target.y)
        }
        onPositionChanged:
        {
            if(pressed)
            {
                var offsetX = mouse.x - startPoint.x;
                var offsetY = mouse.y - startPoint.y;
                print (offsetX, offsetY)
                if ((target.width + offsetX) >= target.minimumWidth && offsetX != 0)
                {
                    target.width += offsetX;
                    target.x = fixedPont.x;
                }
                if ((target.height - offsetY) >= target.minimumHeight && offsetY != 0)
                {
                    target.height -= offsetY;
                    target.y += offsetY;
                }
            }
        }
    }

    MouseArea
    {
        id: area4
        x: 0
        y: 8
        width: 8
        height: target.height - 16
        hoverEnabled: true

        onEntered: cursorShape = Qt.SizeHorCursor;
        onExited: cursorShape = Qt.ArrowCursor;
        onPressed:
        {
            startPoint = Qt.point(mouseX, mouseY);
        }
        onPositionChanged:
        {
            if(pressed)
            {
                var offsetX = mouse.x - startPoint.x;
                if ((target.width - offsetX) >= target.minimumWidth)
                {
                    target.width -= offsetX;
                    target.x += offsetX;
                }
            }
        }
    }



    MouseArea
    {
        id: area6
        x: target.width - 8
        y: 8
        width: 8
        height: target.height - 16
        hoverEnabled: true
        property real fixedX: 0;

        onEntered: cursorShape = Qt.SizeHorCursor;
        onExited: cursorShape = Qt.ArrowCursor;
        onPressed:
        {
            startPoint = Qt.point(mouseX, mouseY);
            fixedPont = Qt.point(target.x, target.y)
        }
        onPositionChanged:
        {
            if(pressed)
            {
                var offsetX = mouse.x - startPoint.x;
                if ((target.width + offsetX) >= target.minimumWidth && offsetX != 0)
                {
                    target.width += offsetX;
                    target.x = fixedPont.x;
                }
            }
        }
    }

    MouseArea
    {
        id: area7
        x: 0
        y: target.height - 8
        width: 8
        height: target.height - 16
        hoverEnabled: true
        property real fixedX: 0;

        onEntered: cursorShape = Qt.SizeBDiagCursor;
        onExited: cursorShape = Qt.ArrowCursor;
        onPressed:
        {
            startPoint = Qt.point(mouseX, mouseY);
            fixedPont = Qt.point(target.x, target.y)
        }
        onPositionChanged:
        {
            if (pressed)
            {
                var offsetX = mouse.x - startPoint.x;
                var offsetY = mouse.y - startPoint.y;
                if ((target.width - offsetX) >= target.minimumWidth && offsetX != 0)
                {
                    target.width -= offsetX;
                    target.x += offsetX;
                }
                if ((target.height + offsetY) >= target.minimumHeight && offsetY != 0)
                {
                    target.height += offsetY;
                    target.y = fixedPont.y;
                }
            }
        }
    }

    MouseArea
    {
        id: area8
        x: 8
        y: target.height - 8
        width: target.height - 16
        height: 8
        hoverEnabled: true
        property real fixedX: 0;

        onEntered: cursorShape = Qt.SizeVerCursor;
        onExited: cursorShape = Qt.ArrowCursor;
        onPressed:
        {
            startPoint = Qt.point(mouseX, mouseY);
            fixedPont = Qt.point(target.x, target.y)
        }
        onPositionChanged:
        {
            if (pressed)
            {
                var offsetY = mouse.y - startPoint.y;
                if ((target.height + offsetY) >= target.minimumHeight && offsetY != 0)
                {
                    target.height += offsetY;
                    target.y = fixedPont.y;
                }
            }
        }
    }

    MouseArea
    {
        id: area9
        x: target.width - 8
        y: target.height - 8
        width: 8
        height: 8
        hoverEnabled: true

        onEntered: cursorShape = Qt.SizeFDiagCursor;
        onExited: cursorShape = Qt.ArrowCursor
        onPressed:
        {
            startPoint = Qt.point(mouseX, mouseY);
            fixedPont = Qt.point(target.x, target.y)
        }
        onPositionChanged:
        {
            if(pressed)
            {
                var offsetX = mouse.x - startPoint.x;
                var offsetY = mouse.y - startPoint.y;
                if ((target.width + offsetX) >= target.minimumWidth && offsetX != 0)
                {
                    target.width += offsetX;
                    target.x = fixedPont.x;
                }
                if ((target.height + offsetY) >= target.minimumHeight && offsetY != 0)
                {
                    target.height += offsetY;
                    target.y = fixedPont.y;
                }
            }
        }
    }
}
