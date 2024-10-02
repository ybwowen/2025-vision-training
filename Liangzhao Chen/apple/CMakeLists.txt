cmake_minimum_required(VERSION 3.10)
project(apple)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

add_executable(apple apple.cpp)
target_link_libraries(apple ${OpenCV_LIBS})

