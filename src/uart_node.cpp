#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Empty.h"
#include "std_msgs/UInt8MultiArray.h"

#include "serial/serial.h"

using serial::Serial;

class SerialCom {
 public:
  SerialCom() {}
  SerialCom(ros::NodeHandle n);
  ~SerialCom();
  void WriteCallback(const std_msgs::UInt8MultiArray::ConstPtr& msg);
 
 private:
  Serial ser;
  ros::Publisher read_pub;
};

SerialCom::SerialCom(ros::NodeHandle n) {

  read_pub = n.advertise<std_msgs::String>("range_read", 1000);
  
  try {
    ser.setPort("/dev/ttyUSB0");
    ser.setBaudrate(9600);
    serial::Timeout to = serial::Timeout::simpleTimeout(1000);
    ser.setTimeout(to);
    ser.open();
  }
  catch (serial::IOException& e) {
    ROS_ERROR_STREAM("Unable to open port ");
  }

  if (ser.isOpen()){
    ROS_INFO_STREAM("Serial Port initialized");
  } else {
    ROS_INFO_STREAM("Serial Port Failure");
  }

}

SerialCom::~SerialCom() {

  std::vector<uint8_t> stop_order;
  stop_order.push_back(0x80);
  stop_order.push_back(0x04);
  stop_order.push_back(0x02);
  stop_order.push_back(0x7A);

  ser.write(stop_order);

}

void SerialCom::WriteCallback(const std_msgs::UInt8MultiArray::ConstPtr& msg) {
    
    ser.write(msg->data);
    if(ser.available()) {
      ROS_INFO_STREAM("Reading from serial port");
      std_msgs::String result;
      result.data = ser.read(ser.available());
      ROS_INFO_STREAM("Read: " << result.data);
      read_pub.publish(result);
    }
}

int main (int argc, char** argv){
    ros::init(argc, argv, "range_measure");
    ros::NodeHandle n;

    SerialCom ser_obj(n);
    ros::Subscriber write_sub = n.subscribe("range_write", 1000, 
                                            &SerialCom::WriteCallback, 
                                            &ser_obj);
    ros::spin();
    return 0;
 
}
