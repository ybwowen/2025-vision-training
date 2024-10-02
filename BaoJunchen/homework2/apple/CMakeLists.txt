cmake_minimum_required(VERSION 3.5.0)
project(apple)

find_package(OpenCV REQUIRED )
find_package(Eigen3 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} ${EIGEN3_INCLUDE_DIRS})

add_executable(apple main3.cpp)

target_link_libraries(apple ${OpenCV_LIBS}  )
target_link_libraries(apple ${EIGEN3_LIBS}  )
