cmake_minimum_required(VERSION 3.14)

project(SensorCapture LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

qt_add_executable(${PROJECT_NAME}
    main.cpp
    application.h application.cpp
    plugininterface.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core)
