#pragma once

#include "HardwareSerial.h"
// #include "Arduino.h"
#include <avr/interrupt.h>
#include "TMC2209.h"

class Consts{

private:
char CHECK_PIN,  STEP_PIN,  EN_PIN,  DIR_PIN,  MS1_PIN,  MS2_PIN,  SPEED_PIN,  ALARM_PIN, RX_PIN, TX_PIN;
TMC2209::SerialAddress MOTOR_UNIT;
TMC2209* driver;
bool DRIVER_UNIT_ENABLE_STATUS;

public:
Consts(char CHECK_PIN_, char STEP_PIN_, char EN_PIN_, char DIR_PIN_, char MS1_PIN_, char MS2_PIN_, char SPEED_PIN_, char ALARM_PIN_, char RX_, char TX_, TMC2209::SerialAddress MOTOR_UNIT_)
    : CHECK_PIN(CHECK_PIN_), STEP_PIN(STEP_PIN_), EN_PIN(EN_PIN_), DIR_PIN(DIR_PIN_), MS1_PIN(MS1_PIN_), MS2_PIN(MS2_PIN_), SPEED_PIN(SPEED_PIN_), ALARM_PIN(ALARM_PIN_), RX_PIN(RX_), TX_PIN(TX_), MOTOR_UNIT(MOTOR_UNIT_){
  
  };

Consts(){

};

 char getCheckPin(){ 
  return CHECK_PIN;
 } 

 char getStepPin(){
  return STEP_PIN;
 }

 char getEnPin(){
  return EN_PIN;
 }
 char getDirPin(){
  return DIR_PIN;
 }

 char getMs1Pin(){
  return MS1_PIN;
 }
 char getMs2Pin (){
  return MS2_PIN;
 }
 char getSpeedPin(){
  return SPEED_PIN;
 }
 char getAlarmPin(){
  return ALARM_PIN;
 }
 char getRxPin(){
  return RX_PIN;
 }
 char getTxPin(){
  return TX_PIN;
 }
 TMC2209::SerialAddress getMotorUnit(){
  return MOTOR_UNIT;
 }
 void setDriver(TMC2209* DRIVER_){
  driver = DRIVER_;
 }
 TMC2209* getDriver(){
  return driver;
 }
 void setDriverUnitEnableStatus(bool status){
  DRIVER_UNIT_ENABLE_STATUS = status;
 }
 bool getDriverUnitEnableStatus(){
  return DRIVER_UNIT_ENABLE_STATUS;
 }

};