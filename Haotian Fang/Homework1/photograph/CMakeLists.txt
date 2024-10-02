cmake_minimum_required(VERSION 3.10)
project(PointCloudProjection)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Add your source files
add_executable(PointCloudProjection main.cpp)

# Include OpenCV headers
target_include_directories(PointCloudProjection PRIVATE ${OpenCV_INCLUDE_DIRS})

# Link OpenCV libraries
target_link_libraries(PointCloudProjection PRIVATE ${OpenCV_LIBS})