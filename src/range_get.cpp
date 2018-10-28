#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/UInt8MultiArray.h"

void RangeCallback(const std_msgs::String& range) {
  std::cout << range.data << std::endl;
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "range_get");
  ros::NodeHandle n;


  ros::Subscriber range_sub = n.subscribe("range_read", 100, RangeCallback);
  ros::spin();
  return 0;
}
