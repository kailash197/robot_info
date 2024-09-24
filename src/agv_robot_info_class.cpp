#include "../include/robot_info/robot_info_class.h"
#include <robotinfo_msgs/RobotInfo10Fields.h>
#include <string>

using namespace std;

class AGVRobotInfo : public RobotInfo {
private:
  double maximum_payload; // max weight robot can transport, only AGVs
public:
  AGVRobotInfo(string description, string serial, string ip, string firmware,
               double max_payload);
  void publish_data() override;
};

AGVRobotInfo::AGVRobotInfo(string description, string serial, string ip_add,
                           string firmware, double max_payload)
    : RobotInfo(description, serial, ip_add, firmware),
      maximum_payload(max_payload) {
  ROS_INFO("AGV Robot Node created");
}

void AGVRobotInfo::publish_data() {
  robotinfo_msgs::RobotInfo10Fields message;
  message.data_field_01 = "robot_description: " + this->robot_description;
  message.data_field_02 = "serial_number: " + this->serial_number;
  message.data_field_03 = "ip_address: " + this->ip_address;
  message.data_field_04 = "firmware_version: " + this->firmware_version;
  message.data_field_05 =
      "maximum_payload: " + to_string(this->maximum_payload);

  this->info_publisher.publish(message);
  ROS_INFO("AGV Robot Info Published.");
}
