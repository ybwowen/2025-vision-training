cmake_minimum_required(VERSION 3.11)

project(photograph)
#c++ 20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


find_package(OpenCV REQUIRED)
find_package (Eigen3 3.3 REQUIRED NO_MODULE)
include_directories(${Eigen3_INCLUDE_DIRS})

add_executable(photograph photo.cpp)

# 链接OpenCV库
target_link_libraries(photograph ${OpenCV_LIBS} Eigen3::Eigen)