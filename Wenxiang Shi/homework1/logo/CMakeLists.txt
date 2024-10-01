# Minimum CMake version requirement
cmake_minimum_required(VERSION 3.10)

# Project name and C++ standard
project(logo)
set(CMAKE_CXX_STANDARD 11)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Export compile commands (for code completion in some IDEs)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the executable
add_executable(logo logo.cpp)

# Link the OpenCV libraries
target_link_libraries(logo ${OpenCV_LIBS})