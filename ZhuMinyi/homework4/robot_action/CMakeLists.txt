cmake_minimum_required(VERSION 3.8)
project(robot_action)

# Standard settings
add_compile_options("-std=c++17")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(unique_identifier_msgs REQUIRED)
find_package(rclcpp_action REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "action/Move.action"
)

add_executable(server src/server.cpp)
ament_target_dependencies(server rclcpp rosidl_typesupport_cpp std_msgs geometry_msgs rclcpp_action unique_identifier_msgs) 

add_executable(client src/client.cpp)
ament_target_dependencies(client rclcpp rosidl_typesupport_cpp std_msgs geometry_msgs rclcpp_action unique_identifier_msgs) 

rosidl_get_typesupport_target(typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(server ${typesupport_target})
target_link_libraries(client ${typesupport_target})

# Install the binaries
install(DIRECTORY launch config
DESTINATION share/${PROJECT_NAME})

install(TARGETS
  server
  client
  DESTINATION lib/${PROJECT_NAME})


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
