cmake_minimum_required(VERSION 3.15)

project(DEMO)

find_package(OpenCV 4 REQUIRED)
link_libraries(${OpenCV_LIBS})

add_executable(DEMO main.cpp)