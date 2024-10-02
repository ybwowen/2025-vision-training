cmake_minimum_required(VERSION 3.10)
project(armor)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

add_executable(armor armor.cpp)
target_link_libraries(armor ${OpenCV_LIBS})

