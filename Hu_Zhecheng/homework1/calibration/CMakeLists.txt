cmake_minimum_required(VERSION 3.10)
project(calibration)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

add_executable(calibration calibration.cpp)
target_link_libraries(calibration ${OpenCV_LIBS})