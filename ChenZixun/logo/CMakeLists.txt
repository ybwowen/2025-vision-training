cmake_minimum_required(VERSION 3.22.1)

project(logo)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

add_executable(logo logo.cpp)

target_link_libraries(logo ${OpenCV_LIBS})
target_link_libraries(logo ${EIGEN3_LIBS})
