cmake_minimum_required(VERSION 3.10)

project(armor)

set(CMAKE_CXX_STANDARD 17)

find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)

link_libraries(${OpenCV_LIBS})

include_directories(../assets)

add_executable(armor armor.cpp)
target_link_libraries(armor ${OPENCV_LIBS})