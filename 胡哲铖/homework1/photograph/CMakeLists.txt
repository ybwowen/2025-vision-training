cmake_minimum_required(VERSION 3.1)

project(photograph)

find_package(OpenCV REQUIRED)
find_package (Eigen3 3.3 REQUIRED NO_MODULE)
include_directories(${Eigen3_INCLUDE_DIRS})

add_executable(photograph photograph.cpp)

# 链接OpenCV库
target_link_libraries(photograph ${OpenCV_LIBS} Eigen3::Eigen)
