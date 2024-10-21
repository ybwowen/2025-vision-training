cmake_minimum_required(VERSION 3.8)
project(action_demo)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(action_interfaces REQUIRED)

add_executable(action_robot 
    src/robot.cpp
    src/action_robot.cpp
)
target_include_directories(action_robot PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(action_robot PUBLIC c_std_99 cxx_std_17)
ament_target_dependencies(
  action_robot
  "rclcpp"
  "rclcpp_action"
  "action_interfaces"
)

install(TARGETS action_robot
  DESTINATION lib/${PROJECT_NAME})

add_executable(action_control 
  src/action_control.cpp
)
target_include_directories(action_control PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
$<INSTALL_INTERFACE:include>)
target_compile_features(action_control PUBLIC c_std_99 cxx_std_17)
ament_target_dependencies(
  action_control
  "rclcpp"
  "rclcpp_action"
  "action_interfaces"
)

install(TARGETS action_control
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
