cmake_minimum_required(VERSION 3.22)

project(photograph)
set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS} ${EIGEN3_INCLUDE_DIRS})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(photograph photograph.cpp)

target_link_libraries(photograph ${OpenCV_LIBS})
