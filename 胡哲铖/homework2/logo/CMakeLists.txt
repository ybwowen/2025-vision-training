cmake_minimum_required(VERSION 3.10)
project(logo)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
find_package (Eigen3 3.3 REQUIRED NO_MODULE)
include_directories(${Eigen3_INCLUDE_DIRS})

add_executable(logo logo.cpp)
target_link_libraries(logo ${OpenCV_LIBS} Eigen3::Eigen)