#include "../include/robot_info/hydraulic_system_monitor.h"
#include <string>

using namespace std;

HydraulicSystemMonitor::HydraulicSystemMonitor(string temperature, string level,
                                               string pressure)
    : hydraulic_oil_temperature(temperature),
      hydraulic_oil_tank_fill_level(level), hydraulic_oil_pressure(pressure){};

string HydraulicSystemMonitor::get_hydraulic_oil_temperature() {
  return hydraulic_oil_temperature;
}
string HydraulicSystemMonitor::get_hydraulic_oil_tank_fill_level() {
  return hydraulic_oil_tank_fill_level;
}
string HydraulicSystemMonitor::get_hydraulic_oil_pressure() {
  return hydraulic_oil_pressure;
}