cmake_minimum_required(VERSION 3.11)

project(logo)
#c++ 20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


find_package(OpenCV REQUIRED)
find_package (Eigen3 3.3 REQUIRED NO_MODULE)
include_directories(${Eigen3_INCLUDE_DIRS})

add_executable(logo logo.cpp)

# 链接OpenCV库
target_link_libraries(logo ${OpenCV_LIBS} Eigen3::Eigen)