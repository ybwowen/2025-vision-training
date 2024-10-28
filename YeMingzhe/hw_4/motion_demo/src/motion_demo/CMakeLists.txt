cmake_minimum_required(VERSION 3.8)
project(motion_demo)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(example_interfaces REQUIRED)

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

add_executable(motion_server src/motion_server.cpp)
ament_target_dependencies(motion_server rclcpp rclcpp_action example_interfaces)

add_executable(motion_client src/motion_client.cpp)
ament_target_dependencies(motion_client rclcpp rclcpp_action example_interfaces)

install(TARGETS
  motion_server
  motion_client
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY config launch
  DESTINATION share/${PROJECT_NAME})


ament_package()
