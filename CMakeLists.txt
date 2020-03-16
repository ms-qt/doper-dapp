cmake_minimum_required(VERSION 3.5)

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

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# 平台判断
# LINUX平台判断
if (UNIX AND NOT APPLE)
    set(LINUX 1)
endif (UNIX AND NOT APPLE)


if (APPLE)
    include(AppleCMakeLists.cmake)
endif (APPLE)

if (WIN32)
    include(Win32CMakeLists.cmake)
endif (WIN32)



