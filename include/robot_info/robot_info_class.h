#pragma once

#include "ros/node_handle.h"
#include <ros/ros.h>
using namespace std;
class RobotInfo {
protected:
  string robot_description; // the brand or make
  string serial_number;     // robot's serial number
  string ip_address;        // robot's IP Address
  string firmware_version;  // robot's Firmware version

  ros::Publisher info_publisher; // publish all info
  ros::NodeHandle nh_;

public:
  RobotInfo(string description, string serial, string ip, string firmware);
  virtual void publish_data();
};