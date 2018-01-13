#include "../Adafruit_INA219.h"
#include <iostream>


int main(int argc, char const *argv[])
{
  

  uint32_t currentFrequency;
    
  std::cout << "Hello!" << std::endl;
  
  // Initialize the INA219.
  // By default the initialization will use the largest range (32V, 2A).  However
  // you can call a setCalibration function to change this range (see comments).
  Adafruit_INA219 ina219;
  ina219.begin(41);
  // To use a slightly lower 32V, 1A range (higher precision on amps):
  ina219.setCalibration_32V_1A();
  // Or to use a lower 16V, 400mA range (higher precision on volts and amps):
  //ina219.setCalibration_16V_400mA();

  float shuntvoltage = 0;
  float busvoltage = 0;
  float current_mA = 0;
  float loadvoltage = 0;

  shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  
  std::cout << "Bus Voltage:   " << busvoltage   << " V" << std::endl;
  std::cout << "Shunt Voltage: " << shuntvoltage << " mV" << std::endl;
  std::cout << "Load Voltage:  " << loadvoltage  << " V" << std::endl;
  std::cout << "Current:       " << current_mA   << " mA" << std::endl;
  std::cout << std::endl << std::endl;

  return 0;
}
