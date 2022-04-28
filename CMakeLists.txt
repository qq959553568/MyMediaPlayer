cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)

set(project_name TestWindow)

project(${project_name})

#打开全局moc
set(CMAKE_AUTOMOC ON)
#打开全局uic
set(CMAKE_AUTOUIC ON)
#打开全局rcc，本示例中没有使用qrc，此句可以去掉
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED Widgets)

set(MyMediaPlayer mainwindow)
add_executable(${MyMediaPlayer} main.cpp mainwindow.cpp mainwindow.h mainwindow.ui)
target_link_libraries(${MyMediaPlayer} Qt5::Widgets)