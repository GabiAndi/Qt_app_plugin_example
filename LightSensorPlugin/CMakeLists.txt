cmake_minimum_required(VERSION 3.14)

project(LightSensorPlugin LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

qt_add_plugin(${PROJECT_NAME} CLASS_NAME ${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
    lightsensorplugin.cpp
    lightsensorplugin.h
)

target_include_directories(${PROJECT_NAME} PRIVATE ../SensorCapture)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
)
