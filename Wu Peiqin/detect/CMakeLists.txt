cmake_minimum_required(VERSION 3.8)

project(detect)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# TensorFlow library paths
set(TENSORFLOW_LIB /usr/local/lib/libtensorflow.so)
set(TENSORFLOW_INCLUDE /usr/local/include)

# Include TensorFlow headers
include_directories(${TENSORFLOW_INCLUDE})

add_executable(detect detect.cpp)

target_link_libraries(detect ${OpenCV_LIBS})
# Link TensorFlow library
target_link_libraries(detect ${TENSORFLOW_LIB})