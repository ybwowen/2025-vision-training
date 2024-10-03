cmake_minimum_required(VERSION 3.10)

# 项目名称
project(MyProject)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 查找 OpenCV 库
find_package(OpenCV REQUIRED)

# 查找 Eigen3 库
find_package(Eigen3 REQUIRED)

# 添加源文件
add_executable(main main.cpp)

# 链接 OpenCV 库
target_link_libraries(main ${OpenCV_LIBS})

# 链接 Eigen3 库
target_link_libraries(main Eigen3::Eigen)