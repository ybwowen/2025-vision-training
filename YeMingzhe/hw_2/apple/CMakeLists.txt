cmake_minimum_required(VERSION 3.10)

project(calibration)

# 设置 OpenCV 安装路径
set(OpenCV_DIR /home/nano/OpenCV4/lib/cmake/opencv4/)

find_package(OpenCV REQUIRED)

find_package(Eigen3 REQUIRED)

# 包含 OpenCV 和 Eigen 头文件路径
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${EIGEN3_INCLUDE_DIR})

# 添加可执行文件
add_executable(photograph main.cpp)

# 链接 OpenCV 和 Eigen 库
target_link_libraries(photograph PRIVATE ${OpenCV_LIBS})
