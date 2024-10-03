cmake_minimum_required(VERSION 3.10)
project(dollar)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

add_executable(dollar dollar.cpp)
target_link_libraries(dollar ${OpenCV_LIBS})

