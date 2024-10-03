cmake_minimum_required(VERSION 3.5)

project(armor)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)
find_package (Eigen3 3.3 REQUIRED NO_MODULE)
include_directories(${Eigen3_INCLUDE_DIRS} assets)

add_executable(armor armor.cpp)

# 链接OpenCV库
target_link_libraries(armor ${OpenCV_LIBS} Eigen3::Eigen)
