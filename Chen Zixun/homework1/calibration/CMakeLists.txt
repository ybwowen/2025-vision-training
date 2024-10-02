cmake_minimum_required(VERSION 3.22.1)
project(calibration)
find_package(OpenCV REQUIRED)

add_executable(calibration calibration.cpp)
target_link_libraries(calibration ${OpenCV_LIBS})
