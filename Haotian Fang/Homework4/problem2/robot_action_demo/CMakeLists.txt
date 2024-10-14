cmake_minimum_required(VERSION 3.8)
project(robot_action_demo)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "action/Move.action"
)

add_executable(move_action_server src/move_action_server.cpp)
ament_target_dependencies(move_action_server rclcpp rclcpp_action)

add_executable(move_action_client src/move_action_client.cpp)
ament_target_dependencies(move_action_client rclcpp rclcpp_action)

rosidl_target_interfaces(move_action_server
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

rosidl_target_interfaces(move_action_client
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

install(TARGETS
  move_action_server
  move_action_client
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY
  launch
  config
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()