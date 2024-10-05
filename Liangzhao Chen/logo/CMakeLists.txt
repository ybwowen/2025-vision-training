cmake_minimum_required(VERSION 3.10)
project(logo)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

add_executable(logo logo.cpp)
target_link_libraries(logo ${OpenCV_LIBS})

