# 项目MacOS平台移植

## 开发工具

- Clion

- QtCreate


## CMake需要设置的属性

Qt5Core_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5Core;
Qt5Gui_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5Gui;
Qt5Network_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5Network;
Qt5QmlModels_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5QmlModels;
Qt5Qml_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5Qml;
Qt5Quick_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5Quick;
Qt5_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5;
Qt5MacExtras_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5Macextras;
Qt5DBus_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5DBus;
folly_DIR=/Users/maohuawei/dev/vcpkg/installed/x64-osx/share/folly;
glog_DIR=/Users/maohuawei/dev/vcpkg/installed/x64-osx/share/glog;
gflags_DIR=/Users/maohuawei/dev/vcpkg/installed/x64-osx/share/gflags;
rxcpp_DIR=/Users/maohuawei/dev/vcpkg/installed/x64-osx/share/rxcpp;
rxqt_DIE=/Users/maohuawei/dev/vcpkg/installed/x64-osx/share/rxqt;
yarpl_DIR=/usr/local/lib/cmake/yarpl;
rsocket_DIR=/usr/local/lib/cmake/rsocket;
   


## Qt Create 

Qt5DBus_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5DBus
Qt5Gui_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5Gui
Qt5MacExtras_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5Macextras
Qt5Network_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5Network
Qt5QmlModels_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5QmlModels
Qt5Qml_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5Qml
Qt5Quick_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5Quick
Qt5_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5
folly_DIR=/Users/maohuawei/dev/vcpkg/installed/x64-osx/share/folly
gflags_DIR=/Users/maohuawei/dev/vcpkg/installed/x64-osx/share/gflags
glog_DIR=/Users/maohuawei/dev/vcpkg/installed/x64-osx/share/glog
rsocket_DIR=/usr/local/lib/cmake/rsocket
rxcpp_DIR=/Users/maohuawei/dev/vcpkg/installed/x64-osx/share/rxcpp
rxqt_DIE=/Users/maohuawei/dev/vcpkg/installed/x64-osx/share/rxqt
yarpl_DIR=/usr/local/lib/cmake/yarpl


##  设置Cmake环境

### mac os Clion QtCreate cmake配置环境


Qt5Core_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5Core;Qt5Gui_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5Gui;Qt5Network_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5Network;Qt5QmlModels_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5QmlModels;Qt5Qml_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5Qml;Qt5Quick_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5Quick;Qt5_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5;Qt5MacExtras_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5Macextras;Qt5DBus_DIR=/Users/maohuawei/Qt5.14.1/5.14.1/clang_64/lib/cmake/Qt5DBus;folly_DIR=/Users/maohuawei/dev/vcpkg/installed/x64-osx/share/folly;glog_DIR=/Users/maohuawei/dev/vcpkg/installed/x64-osx/share/glog;gflags_DIR=/Users/maohuawei/dev/vcpkg/installed/x64-osx/share/gflags;yarpl_DIR=/usr/local/lib/cmake/yarpl;rsocket_DIR=/usr/local/lib/cmake/rsocket;rxcpp_DIR=/Users/maohuawei/dev/vcpkg/installed/x64-osx/share/rxcpp