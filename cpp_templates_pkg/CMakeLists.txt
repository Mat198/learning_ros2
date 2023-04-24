cmake_minimum_required(VERSION 3.8)
project(cpp_templates_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

set(ROS_DEPENDENCIES
  rclcpp
)

# Simple node build & install
add_executable(simple_node src/simple_node.cpp)
ament_target_dependencies(simple_node ${ROS_DEPENDENCIES})

install(TARGETS
  simple_node
  DESTINATION  lib/${PROJECT_NAME}
)

# Simple class node build & install
add_executable(class_node src/simple_class_node.cpp)
ament_target_dependencies(class_node ${ROS_DEPENDENCIES})

install(TARGETS
  class_node
  DESTINATION  lib/${PROJECT_NAME}
)


# Build test template. Can be removed safely
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

install(TARGETS
  simple_node
  DESTINATION  lib/${PROJECT_NAME}
)

ament_package()
