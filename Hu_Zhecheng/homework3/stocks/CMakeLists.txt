cmake_minimum_required(VERSION 3.5)

project(stocks)

set(CMAKE_CXX_STANDARD 17)
find_package (Eigen3 3.3 REQUIRED NO_MODULE)
include_directories(${Eigen3_INCLUDE_DIRS})

add_executable(stocks stocks.cpp)

# 链接OpenCV库
target_link_libraries(stocks Eigen3::Eigen)
