cmake_minimum_required(VERSION 3.22.1)
project(armor)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

add_executable(armor armor.cpp)

target_link_libraries(armor ${OpenCV_LIBS})
target_link_libraries(armor ${EIGEN3_LIBS})
