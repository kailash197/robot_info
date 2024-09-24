#pragma once

#include "robot_info_class.h"

class AGVRobotInfo : public RobotInfo {
private:
  double maximum_payload; // max weight robot can transport, only AGVs
public:
  AGVRobotInfo(string description, string serial, string ip, string firmware,
               double max_payload);
  void publish_data() override;
};