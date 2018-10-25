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

add_executable(range_main
  src/main.cpp
)
target_link_libraries(range_main
  ${catkin_LIBRARIES}
)
