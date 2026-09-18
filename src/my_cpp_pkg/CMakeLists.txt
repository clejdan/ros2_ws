cmake_minimum_required(VERSION 3.20)
project(my_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(my_robot_interfaces REQUIRED)

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

add_executable(test_node src/my_first_node.cpp)
add_executable(number_publisher src/number_publisher.cpp)
add_executable(number_counter src/number_counter.cpp)

target_link_libraries(test_node rclcpp::rclcpp)
target_link_libraries(number_publisher rclcpp::rclcpp ${example_interfaces_TARGETS}
${my_robot_interfaces_TARGETS})
target_link_libraries(number_counter rclcpp::rclcpp ${example_interfaces_TARGETS}
${my_robot_interfaces_TARGETS})

install(TARGETS
  test_node
  number_publisher
  number_counter
  DESTINATION lib/${PROJECT_NAME}/
)

ament_package()
