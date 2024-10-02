cmake_minimum_required(VERSION 3.22.1)
project(photograph)
find_package(OpenCV REQUIRED)

add_executable(photograph photograph.cpp)
target_link_libraries(photograph ${OpenCV_LIBS})
