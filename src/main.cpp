#include <iostream>
#include <string>
#include <vector>

#include "serial/serial.h"
#include "ros/ros.h"

using serial::Serial;

int main(int argc, char** argv) {
  ros::init(argc, argv, "range_measure");
  ros::NodeHandle n;
  Serial ser;
  ser.setPort("tty/ttyUSB0");
  return 0;
}
