cmake_minimum_required(VERSION 3.0)
project(chess)

set(CMAKE_CXX_STANDARD 17)

find_package( OpenCV REQUIRED )

include_directories(${OpenCV_INCLUDE_DIRS})

link_libraries(${OpenCV_LIBS})
add_executable(main main.cpp)

target_link_libraries(main ${OpenCV_LIBS})