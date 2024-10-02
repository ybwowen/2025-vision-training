# Minimum CMake version requirement
cmake_minimum_required(VERSION 3.10)

# Project name and C++ standard
project(apple)
set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${EIGEN3_INCLUDE_DIR})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the executable
add_executable(apple main.cpp)

# Link the OpenCV libraries
target_link_libraries(apple ${OpenCV_LIBS})
target_link_libraries(apple Eigen3::Eigen)