cmake_minimum_required(VERSION 3.8)
project(cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

add_executable(cpp_node src/simple_node.cpp)
ament_target_dependencies(cpp_node rclcpp)

add_executable(class_cpp_node src/class_node.cpp)
ament_target_dependencies(class_cpp_node rclcpp)


install(TARGETS
  cpp_node
  class_cpp_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
