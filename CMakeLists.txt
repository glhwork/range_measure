cmake_minimum_required(VERSION 2.8.3)
project(range_measure)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  serial
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

catkin_package(

)

add_executable(range_main
  src/main.cpp
)
target_link_libraries(range_main
  ${catkin_LIBRARIES}
)

add_executable(order_send
  src/order_send.cpp
)
target_link_libraries(order_send
  ${catkin_LIBRARIES}
)

add_executable(range_get
  src/range_get.cpp
)
target_link_libraries(range_get
  ${catkin_LIBRARIES}
)

add_executable(uart_node
  src/uart_node.cpp
)
target_link_libraries(uart_node
  ${catkin_LIBRARIES}
)
