cmake_minimum_required(VERSION 3.5.0)
project(logo VERSION 0.1.0 LANGUAGES C CXX)


find_package(OpenCV REQUIRED )
find_package(Eigen3 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS} ${EIGEN3_INCLUDE_DIRS})

add_executable(logo main.cpp)

target_link_libraries(logo ${OpenCV_LIBS})
target_link_libraries(logo ${EIGEN3_LIBS})