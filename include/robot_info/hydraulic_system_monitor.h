#pragma once
#include <string>

using namespace std;

class HydraulicSystemMonitor {
private:
  string hydraulic_oil_temperature;
  string hydraulic_oil_tank_fill_level;
  string hydraulic_oil_pressure;

public:
  HydraulicSystemMonitor(string temperature, string level, string pressure);
  string get_hydraulic_oil_temperature(void);
  string get_hydraulic_oil_tank_fill_level(void);
  string get_hydraulic_oil_pressure(void);
};