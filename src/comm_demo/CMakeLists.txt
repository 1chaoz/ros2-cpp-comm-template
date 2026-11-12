cmake_minimum_required(VERSION 3.8)
project(comm_demo)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 查找依赖
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)

# 头文件目录
include_directories(include)

# 所有源文件
add_executable(comm_demo_node
  src/main.cpp
  src/publisher_node.cpp
  src/subscriber_node.cpp
  src/service_server_node.cpp
  src/service_client_node.cpp
)

# 链接 ROS 2 依赖
ament_target_dependencies(comm_demo_node
  rclcpp
  example_interfaces
)

# 安装可执行文件和 launch 文件
install(TARGETS comm_demo_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()