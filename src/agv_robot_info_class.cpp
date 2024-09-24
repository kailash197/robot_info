#include "../include/robot_info/hydraulic_system_monitor.h"
#include "../include/robot_info/robot_info_class.h"
#include <robotinfo_msgs/RobotInfo10Fields.h>
#include <string>

using namespace std;

class AGVRobotInfo : public RobotInfo {
private:
  double maximum_payload; // max weight robot can transport, only AGVs
  HydraulicSystemMonitor hydraulic_system_monitor;

public:
  AGVRobotInfo(string description, string serial, string ip, string firmware,
               double max_payload, HydraulicSystemMonitor *sys_monitor);
  void publish_data() override;
};

AGVRobotInfo::AGVRobotInfo(string description, string serial, string ip_add,
                           string firmware, double max_payload,
                           HydraulicSystemMonitor *sys_monitor)
    : RobotInfo(description, serial, ip_add, firmware),
      maximum_payload(max_payload), hydraulic_system_monitor(*sys_monitor) {
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
  message.data_field_06 =
      "hydraulic_oil_temperature: " +
      this->hydraulic_system_monitor.get_hydraulic_oil_temperature() + "C";
  message.data_field_07 =
      "hydraulic_oil_tank_fill_level: " +
      this->hydraulic_system_monitor.get_hydraulic_oil_tank_fill_level() + "%";
  message.data_field_08 =
      "hydraulic_oil_pressure: " +
      this->hydraulic_system_monitor.get_hydraulic_oil_pressure() + " bar";
  this->info_publisher.publish(message);
  ROS_INFO("AGV Robot Info Published.");
}
