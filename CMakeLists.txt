cmake_minimum_required(VERSION 3.5)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# 组织信息
set(IDENTIFIER "bdlbsc")
set(COPYRIGHT "Copyright © 2019-2020 bdlbsc")
# 项目名称 版本
project(app VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# c++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 平台判断
# LINUX平台判断
if (UNIX AND NOT APPLE)
    set(LINUX 1)
endif (UNIX AND NOT APPLE)


#if (CMAKE_HOST_WIN32)
#    message("当前系统为WIN32")
#    set(WIN32 1)
#elseif (CMAKE_HOST_APPLE)
#    message("当前系统为APPLE")
#    set(APPLE 1)
#elseif (CMAKE_HOST_UNIX)
#    message("当前系统为UNIX")
#    set(LINUX 1)
#endif ()

if (WIN32)
    set(DEVELOPER MS)
endif (WIN32)

if (NOT WIN32)
    include(cmake/ECMInstallIcons.cmake)
endif (NOT WIN32)


find_package(Qt5 COMPONENTS Core Quick Qml Sql Network Widgets WebEngine WebChannel Multimedia LinguistTools QuickControls2 REQUIRED)

if (WIN32)
    find_package(zlib)
endif (WIN32)

if (APPLE)
    find_package(Qt5MacExtras REQUIRED)
    find_package(Qt5DBus REQUIRED)
endif (APPLE)

if (UNIX)
    find_package(Qt5DBus REQUIRED)
endif (UNIX)

##############################################

if (APPLE)
    message("配置APPLE VCPKG 路径")
    include_directories(/Users/maohuawei/dev/vcpkg/installed/x64-osx/include)
    link_directories(/Users/maohuawei/dev/vcpkg/installed/x64-osx/lib)
elseif (WIN32)
    if (DEVELOPER STREQUAL ZN)
        message("配置WIN32 VCPKG 路径")
        include_directories(D:/thirdparty/include)
    else (DEVELOPER)
        message("配置WIN32 VCPKG 路径")
        include_directories(D:/Local/vcpkg/installed/x64-windows/include)
        link_directories(D:/Local/vcpkg/installed/x64-windows/lib)
    endif ()
elseif (LINUX)
    message("配置LINUX VCPKG 路径")
    include_directories(/home/dev/Desktop/vcpkg/installed/x64-linux/include)
    link_directories(/home/dev/Desktop/vcpkg/installed/x64-linux/lib)
endif ()

##############################################


if (APPLE)
    message("配置APPLE本地路径")
    include_directories("/usr/local/include")
    link_directories("/usr/local/lib")
elseif (WIN32)
    if (DEVELOPER STREQUAL ZN)

    else (DEVELOPER)
        message("配置WINDOWS本地路径")
        include_directories("D:/Local/libs/include")
        link_directories("D:/Local/libs/lib")
    endif ()

elseif (LINUX)
    message("配置LINUX本地路径")
    include_directories("/usr/local/include")
    link_directories("/usr/local/lib")
endif ()

##############################################

IF (DEVELOPER STREQUAL ZN)
    message("配置WINDOWS本地路径")
    find_package(fmt CONFIG REQUIRED)
    find_package(folly CONFIG REQUIRED)
    find_package(yarpl REQUIRED)
    find_package(rxcpp CONFIG REQUIRED)
ELSE (DEVELOPER)
    message("配置WINDOWS本地路径")
    find_package(folly CONFIG REQUIRED)
    find_package(yarpl REQUIRED)
    find_package(rsocket REQUIRED)
    find_package(rxcpp CONFIG REQUIRED)
ENDIF ()


if (APPLE)
    set(MACOSX_BUNDLE_GUI_IDENTIFIER ${IDENTIFIER})
    set(MACOSX_BUNDLE_BUNDLE_NAME ${PROJECT_NAME})
    set(MACOSX_BUNDLE_COPYRIGHT ${COPYRIGHT})
    set(MACOSX_BUNDLE_SHORT_VERSION_STRING ${spectral_VERSION})
    set(MACOSX_BUNDLE_BUNDLE_VERSION ${spectral_VERSION})
    set(ICON_NAME "icon.icns")
    set(${PROJECT_NAME}_MAC_ICON "${PROJECT_SOURCE_DIR}/icons/${ICON_NAME}")
    set(MACOSX_BUNDLE_ICON_FILE ${ICON_NAME})
    set_property(SOURCE "${${PROJECT_NAME}_MAC_ICON}" PROPERTY
            MACOSX_PACKAGE_LOCATION Resources)
endif (APPLE)


if (WIN32)
    set(app_WINRC app_win32.rc)
    set_property(SOURCE app_win32.rc APPEND PROPERTY
            OBJECT_DEPENDS ${PROJECT_SOURCE_DIR}/icons/icon.ico
            )
endif (WIN32)

#set(QML_IMPORT_PATH  ${CMAKE_SOURCE_DIR}/toou2d)
#set(QML_DESIGNER_IMPORT_PATH  ${CMAKE_SOURCE_DIR}/toou2d)


# qrc 资源

set(app_QRC
        qml.qrc
        images.qrc
        resources.qrc
        theme.qrc
        )

# 代码
set(app_SRC

        src/main.cpp
        src/plugin/AppPluginManager.cpp
        src/plugin/AppPluginManager.h
        src/plugin/Plugin.cpp
        src/plugin/Plugin.h

        src/logger/Logger.cpp
        src/logger/Logger.h
        src/logger/LoggerTemplate.h

        src/utils/MD5Utils.h
        src/utils/SystemUtils.cpp
        src/utils/SystemUtils.h
        src/systemfeatures/Clipboard.cpp
        src/systemfeatures/Clipboard.h

        #        src/im/IM.cpp
        #        src/im/IM.h
        #        src/im/IMProxy.cpp
        #        src/im/IMProxy.h
        #        src/im/IMModel.cpp
        #        src/im/IMModel.h


        src/qrcode/QRCodeGenerator.cpp
        src/qrcode/QRCodeGenerator.h

        src/image/ImageProvider.h
        src/image/ImageProvider.cpp
        src/image/QrCodeImageProvider.h
        src/image/ImageAsyncImageProvider.cpp
        src/image/ImageAsyncImageProvider.h


        src/data/CommonData.h
        src/utils/UUIDUtils.h


        #        src/app/MainQuickView.h
        #        src/app/MainQuickView.cpp
        #        src/app/LoginQuickView.cpp
        #        src/app/LoginQuickView.h
        #        src/app/NotificationQuickView.cpp
        #        src/app/NotificationQuickView.h
        #        src/app/AppQuickViewManager.h
        #        src/app/AppQuickViewManager.cpp
        #        src/net/NetWorkManager.cpp
        #        src/net/NetWorkManager.h
        #
        #
        #        src/db/CertificateDB.cpp
        #        src/db/CertificateDB.h
        #        src/db/CertificateBean.h


        src/model/db/message/MessageTextModel.cpp
        src/model/db/message/MessageTextModel.h
        src/model/db/message/MessageListModel.cpp
        src/model/db/message/MessageListModel.h
        src/model/bean/message/MessageBeanText.cpp
        src/model/bean/message/MessageBeanText.h


        #
        #        src/model/db/organization/OrganizationModel.cpp
        #        src/model/db/organization/OrganizationModel.h
        #        src/model/db/organization/OrganizationDepartmentModel.cpp
        #        src/model/db/organization/OrganizationDepartmentModel.h
        #        src/model/db/organization/OrganizationMemberModel.cpp
        #        src/model/db/organization/OrganizationMemberModel.h
        #
        #        src/model/db/room/RoomP2PModel.cpp
        #        src/model/db/room/RoomP2PModel.h
        #        src/model/db/room/RoomGroupModel.cpp
        #        src/model/db/room/RoomGroupModel.h
        #        src/model/db/room/RoomTaskModel.cpp
        #        src/model/db/room/RoomTaskModel.h
        #        src/model/db/room/RoomDiscussionGroupModel.cpp
        #        src/model/db/room/RoomDiscussionGroupModel.h
        #        src/model/db/room/RoomMenberModel.cpp
        #        src/model/db/room/RoomMenberModel.h
        #        src/model/db/room/RoomMenberModel.cpp
        #        src/model/db/room/RoomMenberModel.h
        src/model/db/room/RoomListModel.cpp
        src/model/db/room/RoomListModel.h
        #
        src/model/db/task/TaskModel.cpp
        src/model/db/task/TaskModel.h
        src/model/db/task/TaskListModel.cpp
        src/model/db/task/TaskListModel.h

        src/model/db/user/UserModel.cpp
        src/model/db/user/UserModel.h


        src/tool/ThreadTool.cpp
        src/tool/ThreadTool.h

        #        src/inter/callback/ICallBack.h
        #        src/im/LoginCallBack.cpp
        #        src/im/LoginCallBack.h
        #        src/app/UIModelProxy.cpp
        #        src/app/UIModelProxy.h

        src/networkserver/HttpClient.h
        src/networkserver/HttpRequest.h
        src/networkserver/HttpResponse.h
        src/networkserver/NetworkDownloadFile.h
        src/networkserver/UdpClient.h
        src/networkserver/UdpServer.h
        src/networkserver/HttpClient.cpp
        src/networkserver/HttpRequest.cpp
        src/networkserver/HttpResponse.cpp
        src/networkserver/NetworkDownloadFile.cpp
        src/networkserver/UdpClient.cpp
        src/networkserver/UdpServer.cpp

        src/notifications/manager.h

        src/TaoJsonModel/TaoJsonTreeModel.h
        src/TaoJsonModel/TaoListModel.h
        src/TaoJsonModel/TaoListModel.inl
        src/TaoJsonModel/Tools.h
        src/TaoJsonModel/FileReadWrite.h
        src/TaoJsonModel/TaoJsonModel
        src/TaoJsonModel/TaoJsonTreeModel.cpp


        src/emoji/EmojiModel.cpp
        src/emoji/EmojiModel.h

        #        src/systemfeatures/imageclipboard.cpp
        #        src/systemfeatures/imageclipboard.h


        #        src/app/base/BaseQQuickView.cpp
        #        src/app/base/BaseQQuickView.h
        #        src/model/db/mainleftmenu/MainLeftMenu.cpp
        #        src/model/db/mainleftmenu/MainLeftMenu.h

        src/app/AppInfo.h

        src/local/db/CertificateBean.h
        src/db/CertificateDB.cpp
        src/db/CertificateDB.h

        src/proxy/ui/UIProxy.cpp
        src/proxy/ui/UIProxy.h


        src/login/LoginHandler.cpp
        src/login/LoginHandler.h
        src/model/PluginModel.cpp
        src/model/PluginModel.h
        src/component/DynamicLoadComponent.cpp
        src/component/DynamicLoadComponent.h
        src/model/bean/user/UserBean.cpp
        src/model/bean/user/UserBean.h src/model/bean/room/RoomP2PBean.cpp src/model/bean/room/RoomP2PBean.h)

# 通知代码配置
if (APPLE)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Foundation -framework Cocoa")
    set(app_SRC ${app_SRC}
            src/notifications/managermac.mm)
elseif (WIN32)
    set(app_SRC ${app_SRC}
            src/notifications/managerwin.cpp
            src/notifications/wintoastlib.h
            src/notifications/wintoastlib.cpp)
else ()
    set(app_SRC ${app_SRC}
            src/notifications/managerlinux.cpp)
endif ()

QT5_ADD_RESOURCES(app_QRC_SRC ${app_QRC})

if (APPLE)
    add_executable(${PROJECT_NAME} MACOSX_BUNDLE
            ${${PROJECT_NAME}_MAC_ICON}
            ${app_SRC}
            ${app_QRC_SRC}
            )
endif (APPLE)

#      ${TS_FILES}

if (WIN32)
    add_executable(${PROJECT_NAME} WIN32
            ${app_WINRC}
            ${app_SRC}
            ${app_QRC_SRC}
            )
endif (WIN32)

if (LINUX)
    add_executable(${PROJECT_NAME}
            ${app_SRC}
            ${app_QRC_SRC}
            )
endif (LINUX)


target_compile_definitions(app
        PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(app
        PRIVATE Qt5::Core Qt5::Quick Qt5::Sql Qt5::Network Qt5::Widgets Qt5::WebEngine Qt5::WebChannel Qt5::Multimedia)

# mac 通知使用的库
if (APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::MacExtras)
endif (APPLE)


if (APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE app-plugininterface)
    target_link_libraries(${PROJECT_NAME} PRIVATE Folly::folly Folly::folly_deps Folly::follybenchmark Folly::folly_test_util)
    target_link_libraries(${PROJECT_NAME} PRIVATE yarpl)
    target_link_libraries(${PROJECT_NAME} PRIVATE ReactiveSocket)
    target_link_libraries(${PROJECT_NAME} PRIVATE rxcpp)
    target_link_libraries(${PROJECT_NAME} PRIVATE Toou2D)

endif (APPLE)

if (LINUX)
    target_link_libraries(${PROJECT_NAME} PRIVATE app-plugininterface)
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::DBus)
    target_link_libraries(${PROJECT_NAME} PRIVATE Folly::folly Folly::folly_deps Folly::follybenchmark Folly::folly_test_util)
    target_link_libraries(${PROJECT_NAME} PRIVATE yarpl)
    target_link_libraries(${PROJECT_NAME} PRIVATE ReactiveSocket)
    target_link_libraries(${PROJECT_NAME} PRIVATE rxcpp)
endif (LINUX)

if (WIN32)
    if (DEVELOPER STREQUAL ZN)
        message("配置WIN32本地路径")
        target_link_libraries(${PROJECT_NAME} PRIVATE app-plugininterface)
        target_link_libraries(${PROJECT_NAME} PRIVATE Folly::folly Folly::folly_deps Folly::follybenchmark Folly::folly_test_util)
        target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt fmt::fmt-header-only)
        target_link_libraries(${PROJECT_NAME} PRIVATE ZLIB::ZLIB)
        target_link_libraries(${PROJECT_NAME} PRIVATE rxcpp)
        target_link_libraries(${PROJECT_NAME} PRIVATE D:/thirdparty/lib/yarpl.lib)
        target_link_libraries(${PROJECT_NAME} PRIVATE D:/thirdparty/lib/ReactiveSocket.lib)
    else (DEVELOPER)
        message("配置WIN32本地路径")
        target_link_libraries(${PROJECT_NAME} PRIVATE app-plugininterface)
        target_link_libraries(${PROJECT_NAME} PRIVATE Folly::folly Folly::folly_deps Folly::follybenchmark Folly::folly_test_util)
        target_link_libraries(${PROJECT_NAME} PRIVATE yarpl)
        target_link_libraries(${PROJECT_NAME} PRIVATE ReactiveSocket)
        target_link_libraries(${PROJECT_NAME} PRIVATE rxcpp)
    endif ()

endif (WIN32)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

if (APPLE)
    set_property(TARGET ${PROJECT_NAME} PROPERTY
            MACOSX_BUNDLE_INFO_PLIST "${PROJECT_SOURCE_DIR}/macOS/Info.plist.in")
endif (APPLE)


if (NOT CMAKE_INSTALL_BINDIR)
    set(CMAKE_INSTALL_BINDIR ".")
endif ()

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        BUNDLE DESTINATION ${CMAKE_INSTALL_BINDIR})

if (UNIX)
    install(FILES linux/${IDENTIFIER}.desktop
            DESTINATION ${CMAKE_INSTALL_DATADIR}/applications
            )
    install(FILES linux/${IDENTIFIER}.appdata.xml
            DESTINATION ${CMAKE_INSTALL_DATADIR}/metainfo
            )
    file(GLOB app_icons icons/hicolor/*-apps-org.eu.encom.spectral.png)
    ecm_install_icons(ICONS ${app_icons}
            DESTINATION ${CMAKE_INSTALL_DATADIR}/icons
            )
endif (UNIX)