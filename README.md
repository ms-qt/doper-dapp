
# 添加到编译环境变量

## qt

    Qt5Core_DIR=/Users/maohuawei/dev/Qt/5.14.0/clang_64/lib/cmake/Qt5Core;Qt5Gui_DIR=/Users/maohuawei/dev/Qt/5.14.0/clang_64/lib/cmake/Qt5Gui;Qt5Network_DIR=/Users/maohuawei/dev/Qt/5.14.0/clang_64/lib/cmake/Qt5Network;Qt5QmlModels_DIR=/Users/maohuawei/dev/Qt/5.14.0/clang_64/lib/cmake/Qt5QmlModels;Qt5Qml_DIR=/Users/maohuawei/dev/Qt/5.14.0/clang_64/lib/cmake/Qt5Qml;Qt5Quick_DIR=/Users/maohuawei/dev/Qt/5.14.0/clang_64/lib/cmake/Qt5Quick;Qt5_DIR=/Users/maohuawei/dev/Qt/5.14.0/clang_64/lib/cmake/Qt5
        
## flooy rsocket
   
    Qt5Core_DIR=/Users/maohuawei/dev/Qt/5.14.0/clang_64/lib/cmake/Qt5Core;Qt5Gui_DIR=/Users/maohuawei/dev/Qt/5.14.0/clang_64/lib/cmake/Qt5Gui;Qt5Network_DIR=/Users/maohuawei/dev/Qt/5.14.0/clang_64/lib/cmake/Qt5Network;Qt5QmlModels_DIR=/Users/maohuawei/dev/Qt/5.14.0/clang_64/lib/cmake/Qt5QmlModels;Qt5Qml_DIR=/Users/maohuawei/dev/Qt/5.14.0/clang_64/lib/cmake/Qt5Qml;Qt5Quick_DIR=/Users/maohuawei/dev/Qt/5.14.0/clang_64/lib/cmake/Qt5Quick;Qt5_DIR=/Users/maohuawei/dev/Qt/5.14.0/clang_64/lib/cmake/Qt5;folly_DIR=/Users/maohuawei/dev/vcpkg/installed/x64-osx/share/folly;glog_DIR=/Users/maohuawei/dev/vcpkg/installed/x64-osx/share/glog;gflags_DIR=/Users/maohuawei/dev/vcpkg/installed/x64-osx/share/gflags;yarpl_DIR=/usr/local/lib/cmake/yarpl;rsocket_DIR=/usr/local/lib/cmake/rsocket
   
## cmake编译环境变量
    
    Qt5Core_DIR=/Users/maohuawei/dev/Qt/5.14.0/clang_64/lib/cmake/Qt5Core;
    Qt5Gui_DIR=/Users/maohuawei/dev/Qt/5.14.0/clang_64/lib/cmake/Qt5Gui;
    Qt5Network_DIR=/Users/maohuawei/dev/Qt/5.14.0/clang_64/lib/cmake/Qt5Network;
    Qt5QmlModels_DIR=/Users/maohuawei/dev/Qt/5.14.0/clang_64/lib/cmake/Qt5QmlModels;
    Qt5Qml_DIR=/Users/maohuawei/dev/Qt/5.14.0/clang_64/lib/cmake/Qt5Qml;
    Qt5Quick_DIR=/Users/maohuawei/dev/Qt/5.14.0/clang_64/lib/cmake/Qt5Quick;
    Qt5_DIR=/Users/maohuawei/dev/Qt/5.14.0/clang_64/lib/cmake/Qt5;
    folly_DIR=/Users/maohuawei/dev/vcpkg/installed/x64-osx/share/folly;
    glog_DIR=/Users/maohuawei/dev/vcpkg/installed/x64-osx/share/glog;
    gflags_DIR=/Users/maohuawei/dev/vcpkg/installed/x64-osx/share/gflags;
    yarpl_DIR=/usr/local/lib/cmake/yarpl;
    rsocket_DIR=/usr/local/lib/cmake/rsocket;
        
## RSocket和QT错误检查

- rsocket 相关头文件需要放在qt相关头文件上面
- rsocket 不能使用Q_OBJECT宏


## rsocketcpp 只支持 tcp

http://rsocket.io/docs/Implementations

## 参考代码

https://github.com/facebook/flipper/blob/master/xplat/Flipper/FlipperConnectionManagerImpl.cpp