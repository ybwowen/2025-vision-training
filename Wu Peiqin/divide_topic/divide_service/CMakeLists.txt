cmake_minimum_required(VERSION 3.8)
project(divide_service)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(divide_interfaces REQUIRED)
find_package(rosidl_runtime_cpp REQUIRED)  # 添加这一行

add_executable(divide_server src/divide_server.cpp)
ament_target_dependencies(divide_server rclcpp divide_interfaces)

add_executable(divide_client src/divide_client.cpp)
ament_target_dependencies(divide_client rclcpp divide_interfaces)

install(TARGETS divide_client divide_server
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
