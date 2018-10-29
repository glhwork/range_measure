#include <iostream>
#include <string>
#include <vector>

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/UInt8MultiArray.h"



int main(int argc, char** argv) {
  ros::init(argc, argv, "order_send");
  ros::NodeHandle n;

  ros::Publisher order_pub = n.advertise<std_msgs::UInt8MultiArray>("range_write", 100);
  std_msgs::UInt8MultiArray order;

  order.data.push_back(0x80);
  order.data.push_back(0x06);
  order.data.push_back(0x02);
  order.data.push_back(0x78);

  ros::Rate r(1);
  while(ros::ok()) {
    order_pub.publish(order);
    ros::spinOnce();
    r.sleep();
  }

  return 0;
}
