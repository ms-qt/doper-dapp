# Ubuntu 运行项目

## install

    sudo apt-get install libgl1-mesa-dev libglu1-mesa-dev


## 使用工具

    - Ｃlion
    - QtCreate

## Cmake 设置属性

    Qt5Core_DIR=/home/dev/Qt5.14.0/5.14.0/gcc_64/lib/cmake/Qt5Core;
    Qt5Gui_DIR=/home/dev/Qt5.14.0/5.14.0/gcc_64/lib/cmake/Qt5Gui;
    Qt5Network_DIR=/home/dev/Qt5.14.0/5.14.0/gcc_64/liblib/cmake/Qt5Network;
    Qt5QmlModels_DIR=/home/dev/Qt5.14.0/5.14.0/gcc_64/lib/cmakeQt5QmlModels;
    Qt5Qml_DIR=/home/dev/Qt5.14.0/5.14.0/gcc_64/lib/cmake/Qt5Qml;
    Qt5Quick_DIR=/home/dev/Qt5.14.0/5.14.0/gcc_64/lib/cmake/Qt5Quick;
    Qt5_DIR=/home/dev/Qt5.14.0/5.14.0/gcc_64/lib/cmake/Qt5;
    folly_DIR=/home/dev/Desktop/vcpkg/installed/x64-linux/share/folly;
    glog_DIR=/home/dev/Desktop/vcpkg/installed/x64-linux/share/glog;
    gflags_DIR=/home/dev/Desktop/vcpkg/installed/x64-linux/share/gflags;
    yarpl_DIR=/usr/local/lib/cmake/yarpl;
    rsocket_DIR=/usr/local/lib/cmake/rsocket


## Clion QtCreate CMake 设置环境变量

    Qt5Core_DIR=/home/dev/Qt5.14.0/5.14.0/gcc_64/lib/cmake/Qt5Core;Qt5Gui_DIR=/home/dev/Qt5.14.0/5.14.0/gcc_64/lib/cmake/Qt5Gui;Qt5Network_DIR=/home/dev/Qt5.14.0/5.14.0/gcc_64/liblib/cmake/Qt5Network;Qt5QmlModels_DIR=/home/dev/Qt5.14.0/5.14.0/gcc_64/lib/cmakeQt5QmlModels;Qt5Qml_DIR=/home/dev/Qt5.14.0/5.14.0/gcc_64/lib/cmake/Qt5Qml;Qt5Quick_DIR=/home/dev/Qt5.14.0/5.14.0/gcc_64/lib/cmake/Qt5Quick;Qt5_DIR=/home/dev/Qt5.14.0/5.14.0/gcc_64/lib/cmake/Qt5;folly_DIR=/home/dev/Desktop/vcpkg/installed/x64-linux/share/folly;glog_DIR=/home/dev/Desktop/vcpkg/installed/x64-linux/share/glog;gflags_DIR=/home/dev/Desktop/vcpkg/installed/x64-linux/share/gflags;yarpl_DIR=/usr/local/lib/cmake/yarpl;rsocket_DIR=/usr/local/lib/cmake/rsocket;rxcpp_DIR=/home/dev/Desktop/vcpkg/installed/x64-linux/share/rxcpp;rxqt_DIR=/home/dev/Desktop/vcpkg/installed/x64-linux/share/rxqt;Qt5DBus_DIR=/home/dev/Qt5.14.0/5.14.0/gcc_64/lib/cmake/Qt5DBus
  
  
  
  
## 升级cmake (可选)

    wget https://cmake.org/files/v3.9/cmake-3.9.2.tar.gz
    
    tar -xvf cmake-3.9.2.tar.gz
    
    cd cmake-3.9.2
    
    ./configure
    
    sudo make
    
    sudo make install
    
    hash -r
    
    cmake --version


