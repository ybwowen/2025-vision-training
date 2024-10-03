cmake_minimum_required(VERSION 3.15)

project(DEMO)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS})

add_executable(DEMO main.cpp)