cmake_minimum_required(VERSION 3.15)

project(DEMO)

find_package(OpenCV 4 REQUIRED)
find_package(Eigen3 REQUIRED)
link_libraries(${OpenCV_LIBS})
include_directories(${EIGEN3_INCLUDE_DIRS})

add_executable(DEMO main.cpp)