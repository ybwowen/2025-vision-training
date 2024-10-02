# 设置最低的CMake版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称以及支持的C++标准
project(MyProject LANGUAGES CXX)

# 设置C++标准为 C++11 或者更高
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 查找OpenCV库
find_package(OpenCV REQUIRED)

# 添加头文件目录
include_directories(${OpenCV_INCLUDE_DIRS})

# 设置源文件
add_executable(MyProject main.cpp)

# 链接OpenCV库
target_link_libraries(MyProject ${OpenCV_LIBS})