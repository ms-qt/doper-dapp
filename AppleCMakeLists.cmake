message("start | osx | 平台")

include(cmake/ECMInstallIcons.cmake)

include_directories(/usr/local/dev/vcpkg/installed/x64-osx/include)
link_directories(/usr/local/dev/vcpkg/installed/x64-osx/lib)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

find_package(Qt5Core REQUIRED)
find_package(Qt5Quick REQUIRED)
find_package(Qt5Qml REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5WebEngine REQUIRED)
find_package(Qt5WebChannel REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(Qt5LinguistTools REQUIRED)
find_package(Qt5QuickControls2 REQUIRED)
find_package(Qt5WebSockets REQUIRED)
find_package(Qt5MacExtras REQUIRED)
find_package(Qt5DBus REQUIRED)
find_package(folly CONFIG REQUIRED)
find_package(yarpl REQUIRED)
find_package(rsocket REQUIRED)
find_package(rxcpp CONFIG REQUIRED)
find_package(cryptopp CONFIG REQUIRED)
find_package(bdlbsc-plugin-supper CONFIG REQUIRED)


# 源代码
set(SRC
        bdlbsc/app/main.cpp

        bdlbsc/module/common/Common.cpp
        bdlbsc/module/common/Common.h
        bdlbsc/module/common/Modules.h

        bdlbsc/module/component/DynamicLoadComponent.cpp
        bdlbsc/module/component/DynamicLoadComponent.h


        bdlbsc/module/data/Data.cpp
        bdlbsc/module/data/Data.h
        bdlbsc/module/data/DataDb.cpp
        bdlbsc/module/data/DataDb.h


        bdlbsc/module/downloadfile/DowmloadFileTaskModel.cpp
        bdlbsc/module/downloadfile/DowmloadFileTaskModel.h
        bdlbsc/module/downloadfile/DownloadClient.cpp
        bdlbsc/module/downloadfile/DownloadClient.h
        bdlbsc/module/downloadfile/DownloadFileManagerModel.cpp
        bdlbsc/module/downloadfile/DownloadFileManagerModel.h
        bdlbsc/module/downloadfile/DownloadProxy.cpp
        bdlbsc/module/downloadfile/DownloadProxy.h
        bdlbsc/module/downloadfile/DOWNLOAD_CONSTANT.h


        bdlbsc/module/image/ImageAsyncImageProvider.h
        bdlbsc/module/image/ImageProvider.cpp
        bdlbsc/module/image/ImageProvider.h
        bdlbsc/module/image/QrCodeImageProvider.h


        bdlbsc/module/logger/Logger.cpp
        bdlbsc/module/logger/Logger.h
        bdlbsc/module/logger/LoggerTemplate.h


        bdlbsc/module/networkserver/HttpClient.cpp
        bdlbsc/module/networkserver/HttpClient.h
        bdlbsc/module/networkserver/HttpRequest.cpp
        bdlbsc/module/networkserver/HttpRequest.h
        bdlbsc/module/networkserver/HttpResponse.cpp
        bdlbsc/module/networkserver/HttpResponse.h
        bdlbsc/module/networkserver/NetworkDownloadFile.cpp
        bdlbsc/module/networkserver/NetworkDownloadFile.h
        bdlbsc/module/networkserver/UdpClient.cpp
        bdlbsc/module/networkserver/UdpClient.h
        bdlbsc/module/networkserver/UdpServer.cpp
        bdlbsc/module/networkserver/UdpServer.h


        bdlbsc/module/plugin/Plugin.cpp
        bdlbsc/module/plugin/Plugin.h
        bdlbsc/module/plugin/AppPluginManager.cpp
        bdlbsc/module/plugin/AppPluginManager.h


        bdlbsc/module/qrcode/QRCodeGenerator.cpp
        bdlbsc/module/qrcode/QRCodeGenerator.h


        bdlbsc/module/supper/IData.h
        bdlbsc/module/supper/IMD5Utils.h
        bdlbsc/module/supper/IModule.h
        bdlbsc/module/supper/IStringUtils.h
        bdlbsc/module/supper/IThreadUtils.h
        bdlbsc/module/supper/IUtils.h
        bdlbsc/module/supper/IUUIDUtils.h
        bdlbsc/module/supper/ISystemUtils.h


        bdlbsc/module/systemfeatures/Clipboard.cpp
        bdlbsc/module/systemfeatures/Clipboard.h
        bdlbsc/module/systemfeatures/ImageClipboard.cpp
        bdlbsc/module/systemfeatures/ImageClipboard.h

        bdlbsc/module/utils/SystemUtils.cpp
        bdlbsc/module/utils/SystemUtils.h
        bdlbsc/module/utils/Utils.cpp
        bdlbsc/module/utils/Utils.h
        bdlbsc/module/utils/MD5Utils.cpp
        bdlbsc/module/utils/MD5Utils.h
        bdlbsc/module/utils/StringUtils.cpp
        bdlbsc/module/utils/StringUtils.h
        bdlbsc/module/utils/ThreadUtils.cpp
        bdlbsc/module/utils/ThreadUtils.h
        bdlbsc/module/utils/UUIDUtils.cpp
        bdlbsc/module/utils/UUIDUtils.h
        bdlbsc/module/common/Modules.cpp)


set(MACOSX_BUNDLE_GUI_IDENTIFIER ${IDENTIFIER})
set(MACOSX_BUNDLE_BUNDLE_NAME ${PROJECT_NAME})

set(MACOSX_BUNDLE_COPYRIGHT ${COPYRIGHT})

set(MACOSX_BUNDLE_SHORT_VERSION_STRING ${app_VERSION})
set(MACOSX_BUNDLE_BUNDLE_VERSION ${app_VERSION})


set(ICON_NAME "icon.icns")
set(${PROJECT_NAME}_MAC_ICON "${PROJECT_SOURCE_DIR}/icons/${ICON_NAME}")
set(MACOSX_BUNDLE_ICON_FILE ${ICON_NAME})
set_property(SOURCE "${${PROJECT_NAME}_MAC_ICON}" PROPERTY
        MACOSX_PACKAGE_LOCATION Resources)


set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Foundation -framework Cocoa")


set(SRC ${SRC}
        bdlbsc/module/notifications/manager.h
        bdlbsc/module/notifications/managermac.mm
        )

# qrc 资源
set(QRC
        qml.qrc
        image.qrc
        media.qrc
        )


# 此处的MACOSX_BUNDLE 不能少，否则没有图标
add_executable(${PROJECT_NAME} MACOSX_BUNDLE
        ${${PROJECT_NAME}_MAC_ICON}
        ${SRC}
        ${QRC}
        )


target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Quick)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Sql)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Network)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::WebEngine)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::WebChannel)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Multimedia)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::WebSockets)
# mac 通知使用的库
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::MacExtras)

target_link_libraries(${PROJECT_NAME} PRIVATE Folly::folly Folly::folly_deps Folly::follybenchmark)
target_link_libraries(${PROJECT_NAME} PRIVATE yarpl)
target_link_libraries(${PROJECT_NAME} PRIVATE ReactiveSocket)
target_link_libraries(${PROJECT_NAME} PRIVATE rxcpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Toou2D)
target_link_libraries(${PROJECT_NAME} PRIVATE cryptopp-static)
target_link_libraries(${PROJECT_NAME} PRIVATE bdlbsc-plugin-supper)

set_property(TARGET ${PROJECT_NAME} PROPERTY
        MACOSX_BUNDLE_INFO_PLIST "${PROJECT_SOURCE_DIR}/macOS/Info.plist.in")


# 如果没有指定安装路径
if (NOT CMAKE_INSTALL_BINDIR)
    set(CMAKE_INSTALL_BINDIR ".")
endif ()


# 安装
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        BUNDLE DESTINATION ${CMAKE_INSTALL_BINDIR})
