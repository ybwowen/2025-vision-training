cmake_minimum_required(VERSION 3.10)
project(test)

set(OpenCV_DIR /home/user1/lib/opencv/lib/cmake/opencv4)
set(CMAKE_CXX_STANDARD 11)

find_package( OpenCV REQUIRED )

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("/home/user1/eigen-3.4.0")

add_executable(main camera.cpp)
target_link_libraries(main ${OpenCV_LIBS}  )
