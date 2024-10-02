cmake_minimum_required(VERSION 3.22)

project(calibration)
set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(calibration calibration.cpp)

target_link_libraries(calibration ${OpenCV_LIBS})