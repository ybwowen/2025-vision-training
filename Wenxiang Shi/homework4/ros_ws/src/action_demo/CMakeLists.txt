cmake_minimum_required(VERSION 3.5)
project(action_demo)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rosidl_default_generators REQUIRED)

set(CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(msg_files
  "srv/Action.srv"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
)
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
${CMAKE_CURRENT_BINARY_DIR}/../install/${PROJECT_NAME}/include
)



add_executable(server src/server.cpp)
ament_target_dependencies(server rclcpp)

add_executable(client src/client.cpp)
ament_target_dependencies(client rclcpp)

rosidl_target_interfaces(
  client ${PROJECT_NAME} "rosidl_typesupport_cpp"
)
rosidl_target_interfaces(
  server ${PROJECT_NAME} "rosidl_typesupport_cpp"
)

install(TARGETS
  server
  client
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
