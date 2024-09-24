#include "../include/robot_info/agv_robot_info_class.h"
#include "ros/ros.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "agv_robot_info_node");
  HydraulicSystemMonitor *sys_mon =
      new HydraulicSystemMonitor("45", "100", "250");
  AGVRobotInfo *agv = new AGVRobotInfo("Mir100", "567A359", "169.254.5.180",
                                       "3.5.8", 100.0, sys_mon);
  ros::Rate loop_rate(1);
  while (ros::ok()) {
    agv->publish_data();
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
