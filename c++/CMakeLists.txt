cmake_minimum_required(VERSION 3.26)
project(c__)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(c__ main.cpp
        functions.h)
target_link_libraries(c__
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)

