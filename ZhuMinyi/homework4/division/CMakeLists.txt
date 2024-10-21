cmake_minimum_required(VERSION 3.8)
project(division)

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
find_package(rosidl_typesupport_cpp REQUIRED)  # <-- Add this to link the C++ service type support

# Generate service interface
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/Division.srv"
  DEPENDENCIES builtin_interfaces
)

# Link against generated service libraries
ament_export_dependencies(rosidl_default_runtime rosidl_typesupport_cpp)

# Add the executables for server and client
add_executable(server src/server.cpp)
ament_target_dependencies(server rclcpp rosidl_typesupport_cpp)  # <-- Link generated service

add_executable(client src/client.cpp)
ament_target_dependencies(client rclcpp rosidl_typesupport_cpp)  # <-- Link generated service

# rosidl_target_interfaces(server ${PROJECT_NAME} "rosidl_typesupport_cpp")
# rosidl_target_interfaces(client ${PROJECT_NAME} "rosidl_typesupport_cpp")

# instead
rosidl_get_typesupport_target(typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(server ${typesupport_target})
target_link_libraries(client ${typesupport_target})

# Install the binaries
install(TARGETS
  server
  client
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
