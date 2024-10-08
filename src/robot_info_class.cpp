#include "../include/robot_info/robot_info_class.h"
#include "ros/node_handle.h"
#include <robotinfo_msgs/RobotInfo10Fields.h>
#include <ros/ros.h>
#include <string>

using namespace std;

RobotInfo::RobotInfo(string rd, string sn, string ip, string fv)
    : nh_(), robot_description(rd), serial_number(sn), ip_address(ip),
      firmware_version(fv) {
  info_publisher =
      nh_.advertise<robotinfo_msgs::RobotInfo10Fields>("/robot_info", 1000);
  ROS_INFO("RobotInfo Node created.");
}

void RobotInfo::publish_data() {
  robotinfo_msgs::RobotInfo10Fields message;
  message.data_field_01 = "robot_description: " + this->robot_description;
  message.data_field_02 = "serial_number: " + this->serial_number;
  message.data_field_03 = "ip_address: " + this->ip_address;
  message.data_field_04 = "firmware_version: " + this->firmware_version;
  this->info_publisher.publish(message);
  ROS_INFO("Robot Info Published.");
}
