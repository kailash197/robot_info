#include "../include/robot_info/robot_info_class.h"
#include <iostream>
#include <ros/ros.h>
int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_info_node");
  RobotInfo robot("Mir100", "567A359", "169.254.5.180", "3.5.8");
  ros::Rate loop_rate(1);
  while (ros::ok()) {
    robot.publish_data();
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}