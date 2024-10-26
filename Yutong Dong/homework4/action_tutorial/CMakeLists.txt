cmake_minimum_required(VERSION 3.8)
project(action_tutorial)

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

add_executable(action_server src/action_server.cpp)
ament_target_dependencies(action_server rclcpp rclcpp_action)

add_executable(action_client src/action_client.cpp)
ament_target_dependencies(action_client rclcpp rclcpp_action)

# 使用 rosidl_get_typesupport_target 替代 rosidl_target_interfaces
rosidl_get_typesupport_target(action_server_typesupport
  ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(action_server
  ${action_server_typesupport})

rosidl_get_typesupport_target(action_client_typesupport
  ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(action_client
  ${action_client_typesupport})

install(TARGETS
  action_server
  action_client
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY
  launch
  config
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()
