cmake_minimum_required(VERSION 3.10)

project(calibration)

# 设置 OpenCV 安装路径
set(OpenCV_DIR /home/nano/OpenCV4/lib/cmake/opencv4/)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(calibration main.cpp)

target_link_libraries(calibration PRIVATE ${OpenCV_LIBS})
