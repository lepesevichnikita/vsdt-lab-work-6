cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(vsdt_lab_work_6 VERSION 1.0.0)

set(PROJECT_BINARY_DIR build)
set(CMAKE_AUTOMOC ON)

set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(RESOURCES_DIR "${PROJECT_SOURCE_DIR}/resources")

set(EXECUTABLE_NAME "${PROJECT_NAME}_executable")
set(LIBRARY_NAME "${PROJECT_NAME}.o")
set(APK_NAME "${PROJECT_NAME}")

include_directories(${INCLUDE_DIR})
find_package(Qt5 COMPONENTS Core Widgets Quick Qml Gui REQUIRED)
find_package(Qt5QuickCompiler REQUIRED)

add_subdirectory(src build)

