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
  std::vector<int> v;
  int v1 = 0x80;
  int v2 = 0x06;
  int v3 = 0x02;
  int v4 = 0x78;

  v.push_back(v1);
  v.push_back(v2);
  v.push_back(v3);
  v.push_back(v4);

  
  // for (size_t i = 0; i < v.size(); i++) {
  // 	std::stringstream ss;
  // 	ss << std::hex << v[i];
  // 	std::string s_tmp;
  // 	ss >> s_tmp;
  // 	order.data = order.data + s_tmp + " ";
  // }
  // for (size_t i = 0; i < v.size(); i++) {
  // 	order.data = order.data + v[i] + " ";
  // }
  // order.data = order.data + "\n";

  ros::Rate r(1);
  while(ros::ok()) {
  	order_pub.publish(order);
    ros::spinOnce();
    r.sleep();
  }

  return 0;
}