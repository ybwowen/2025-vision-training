cmake_minimum_required(VERSION 3.22)

project(armor)
set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS} ${EIGEN3_INCLUDE_DIRS})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(armor armor.cpp)

target_link_libraries(armor ${OpenCV_LIBS})