cmake_minimum_required(VERSION 3.8)

project(stocks)

set(CMAKE_CXX_STANDARD 17)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(stocks stocks.cpp)

# 链接Eigen库
target_link_libraries(stocks PRIVATE Eigen3::Eigen)