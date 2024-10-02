cmake_minimum_required(VERSION 3.10)
project(photo)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED )
find_package(Eigen3 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS} ${EIGEN3_INCLUDE_DIRS})


add_executable(photo main2.cpp)
target_link_libraries(photo ${OpenCV_LIBS})
target_link_libraries(photo ${EIGEN3_LIBS})