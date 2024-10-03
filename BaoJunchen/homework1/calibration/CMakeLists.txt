cmake_minimum_required(VERSION 3.10)
project(calibration)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED )

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(calibration main.cpp)
target_link_libraries(calibration ${OpenCV_LIBS}  )