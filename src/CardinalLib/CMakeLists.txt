cmake_minimum_required(VERSION 3.5)

project(CardinalLib LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(CardinalLib STATIC
  shell.h shell.cpp
  app.h app.cpp
  qemu_core.h qemu_core.cpp
)

target_link_libraries(CardinalLib PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(CardinalLib PRIVATE CARDINALLIB_LIBRARY)
