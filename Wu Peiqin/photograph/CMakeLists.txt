cmake_minimum_required(VERSION 3.10)
project(photograph)

set(CMAKE_CXX_STANDARD 20)

find_package( OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN_INCLUDE_DIRS})


link_libraries(${OpenCV_LIBS})
add_executable(photograph main.cpp)

target_link_libraries(photograph ${OpenCV_LIBS})
target_link_libraries(photograph ${E})