cmake_minimum_required(VERSION 3.4)
project(stock)
set(CMAKE_CXX_STANDARD 17)

find_package(Eigen3 3.4 REQUIRED NO_MODULE)

add_executable(stock stock.cpp)

target_link_libraries(stock PRIVATE Eigen3::Eigen)
