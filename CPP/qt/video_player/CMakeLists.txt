project(VideoPlayer)
cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS Multimedia MultimediaWidgets  Widgets Core  REQUIRED)

add_executable(play main.cpp)
target_link_libraries(play Qt5::Multimedia Qt5::MultimediaWidgets Qt5::Widgets Qt5::Core)
