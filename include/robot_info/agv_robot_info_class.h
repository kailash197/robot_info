#pragma once

#include "hydraulic_system_monitor.h"
#include "robot_info_class.h"

class AGVRobotInfo : public RobotInfo {
private:
  double maximum_payload; // max weight robot can transport, only AGVs
  HydraulicSystemMonitor hydraulic_system_monitor;

public:
  AGVRobotInfo(string description, string serial, string ip, string firmware,
               double max_payload, HydraulicSystemMonitor *sys_monitor);
  void publish_data() override;
};