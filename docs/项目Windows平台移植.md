# 项目Windows平台移植



## 开发工具
	
	- Visual Studio 2019 64位

## cmake 配置属性

    "Qt5Core_DIR":"D:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5Core",
    "Qt5Gui_DIR":"D:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5Gui",
    "Qt5Network_DIR":"D:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5Network",
    "Qt5QmlModels_DIR":"D:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmakeQt5QmlModels",
    "Qt5Qml_DIR":"D:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5Qml",
    "Qt5Quick_DIR":"D:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5Quick",
    "Qt5_DIR":"D:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5",
    "folly_DIR":"D:/Local/vcpkg/installed/x64-windows/share/folly",
    "glog_DIR":"D:/Local/vcpkg/installed/x64-windows/share/glog",
    "gflags_DIR":"D:/Local/vcpkg/installed/x64-windows/share/gflags",
    "yarpl_DIR":"D:/Local/libs/lib/cmake/yarpl",
    "rsocket_DIR":"D:/Local/libs/lib/cmake/rsocket"
    
    
    ---
    
        Qt5Core_DIR=C:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5Core;
        Qt5Gui_DIR=C:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5Gui;
        Qt5Network_DIR=C:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5Network;
        Qt5QmlModels_DIR=C:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmakeQt5QmlModels;
        Qt5Qml_DIR=C:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5Qml;
        Qt5Quick_DIR=C:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5Quick;
        Qt5_DIR=C:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5;
        folly_DIR=D:/Local/vcpkg/installed/x64-windows/share/folly;
        glog_DIR=D:/Local/vcpkg/installed/x64-windows/share/glog;
        gflags_DIR=D:/Local/vcpkg/installed/x64-windows/share/gflags;
        yarpl_DIR=D:/Local/libs/lib/cmake/yarpl;
        rsocket_DIR=D:/Local/libs/lib/cmake/rsocket;
        rxcpp_DIR=D:/Local/vcpkg/installed/x64-windows/share/rxcpp;
    
    Qt5Core_DIR=C:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5Core;Qt5Gui_DIR=C:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5Gui;Qt5Network_DIR=C:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5Network;Qt5QmlModels_DIR=C:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmakeQt5QmlModels;Qt5Qml_DIR=C:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5Qml;Qt5Quick_DIR=C:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5Quick;Qt5_DIR=C:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5;folly_DIR=D:/Local/vcpkg/installed/x64-windows/share/folly;glog_DIR=D:/Local/vcpkg/installed/x64-windows/share/glog;gflags_DIR=D:/Local/vcpkg/installed/x64-windows/share/gflags;yarpl_DIR=D:/Local/libs/lib/cmake/yarpl;rsocket_DIR=D:/Local/libs/lib/cmake/rsocket;rxcpp_DIR=D:/Local/vcpkg/installed/x64-windows/share/rxcpp;

## 配置Visual Studio 2019 下的 CMakeSettings.json


- 主要是配置环境变量

- 完整配置文件
	
		
		{
		  "configurations": [
		    {
		      "name": "x64-Release",
		      "generator": "Visual Studio 16 2019 Win64",
		      "configurationType": "Release",
		      "inheritEnvironments": [
		        "msvc_x64_x64"
		      ],
		      "buildRoot": "${env.USERPROFILE}\\CMakeBuilds\\${workspaceHash}\\build\\${name}",
		      "installRoot": "${env.USERPROFILE}\\CMakeBuilds\\${workspaceHash}\\install\\${name}",
		      "cmakeCommandArgs": "",
		      "variables": [
		        {
		          "name": "Qt5Core_DIR",
		          "value": "D:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5Core",
		          "type": "FILEPATH"
		        },
		
		
		        {
		          "name": "Qt5Gui_DIR",
		          "value": "D:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5Gui",
		          "type": "FILEPATH"
		
		        },
		        {
		          "name": " Qt5Network_DIR",
		          "value": "D:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5Network",
		          "type": "FILEPATH"
		
		        },
		        {
		          "name": " Qt5QmlModels_DIR",
		          "value": "D:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmakeQt5QmlModels",
		          "type": "FILEPATH"
		
		        },
		        {
		          "name": " Qt5Qml_DIR",
		          "value": "D:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5Qml",
		          "type": "FILEPATH"
		
		        },
		        {
		          "name": " Qt5Quick_DIR",
		          "value": "D:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5Quick",
		          "type": "FILEPATH"
		
		        },
		        {
		          "name": " Qt5_DIR",
		          "value": "D:/Qt/Qt5.14.0/5.14.0/msvc2017_64/lib/cmake/Qt5",
		          "type": "FILEPATH"
		
		        },
		        {
		          "name": "folly_DIR",
		          "value": "D:/Local/vcpkg/installed/x64-windows/share/folly",
		          "type": "FILEPATH"
		
		        },
		        {
		          "name": "glog_DIR",
		          "value": "D:/Local/vcpkg/installed/x64-windows/share/glog",
		          "type": "FILEPATH"
		
		        },
		        {
		          "name": "gflags_DIR",
		          "value": "D:/Local/vcpkg/installed/x64-windows/share/gflags",
		          "type": "FILEPATH"
		
		        },
		        {
		          "name": "  yarpl_DIR",
		          "value": "D:/Local/libs/lib/cmake/yarpl",
		          "type": "FILEPATH"
		
		        },
		        {
		          "name": "rsocket_DIR",
		          "value": "D:/Local/libs/lib/cmake/rsocket",
		          "type": "FILEPATH"
		        },
		        {
		          "name": "zlib_DIR",
		          "value": "D:/Local/libs/lib/cmake/zlib",
		          "type": "FILEPATH"
		        }
		      ]
		    }
		  ]
		}


## 将qt安装目录添加到环境变量


	D:\Qt\Qt5.14.0\5.14.0\msvc2017_64\bin

- 作用主要是为了使用方便

- 主要使用windeployqt


## 在生成app.exe的目录

- 目录

		C:\Users\dev\CMakeBuilds\9c71ca14-a2ef-462e-8528-d2d1c8e7291b\build\x64-Release\app\Release


- 发布

		windeployqt app.exe


## 将 qt 安装目录下的qml文件夹拷贝到运行目录

	https://www.liangzl.com/get-article-detail-145193.html


## 运行 app.exe


![](https://code.aliyun.com/doper/doper-dapp/raw/windows-dev/docs/image/20200114001.png)
