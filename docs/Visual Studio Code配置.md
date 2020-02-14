

# Visual Studio Code 配置项目开发环境（未完）


## c_cpp_properties.json


        {
            "configurations": [
                {
                    "name": "x64-Release",
                    "includePath": [
                        "${workspaceFolder}/**",
                        "D:/Local/vcpkg/installed/x64-windows/include",
                        "D:/Local/vcpkg/installed/x64-windows-static/include",
                        "D:/Local/libs/include"
                    ],
                    "defines": [
                        "_DEBUG",
                        "UNICODE",
                        "_UNICODE"
                    ],
                    "compilerPath": "D:/Program Files (x86)/Microsoft Visual Studio/2019/Enterprise/VC/Tools/MSVC/14.24.28314/bin/Hostx64/x64/cl.exe",
                    "cStandard": "c11",
                    "cppStandard": "c++20",
                    "intelliSenseMode": "msvc-x64",
                    "configurationProvider": "go2sh.cmake-integration",
                    "windowsSdkVersion": "10.0.17763.0"
                }
            ],
            "version": 4
        }



## settings.json

        {
            "editor.mouseWheelZoom": true,
            "C_Cpp.updateChannel": "Insiders",
            "[c]": {
                "files.encoding": "utf8"
            },
            "[cpp]": {
                "files.encoding": "utf8"
            },
            "cmake.buildArguments": "-DCMAKE_TOOLCHAIN_FILE=D:/Local/vcpkg/scripts/buildsystems/vcpkg.cmake",
            "cmake.buildTask": true,
            "cmake.configureSettings": {
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
            }   
        }
