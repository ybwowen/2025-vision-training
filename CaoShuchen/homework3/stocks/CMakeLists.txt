cmake_minimum_required(VERSION 3.22)

project(stocks)
set(CMAKE_CXX_STANDARD 11)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} stocks.cpp)
