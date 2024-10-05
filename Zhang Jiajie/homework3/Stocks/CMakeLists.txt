# Minimum CMake version required
cmake_minimum_required(VERSION 3.14)

# Project name
project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Eigen3 package
find_package(Eigen3 3.3 REQUIRED)

# Add the executable, assuming main.cpp is in the project root directory
add_executable(${PROJECT_NAME} main.cpp)

# Link Eigen3 to your project
target_link_libraries(${PROJECT_NAME} Eigen3::Eigen)