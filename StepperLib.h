#pragma once

#include <Arduino.h>
#include "TMC2209.h"
#include <SoftwareSerial.h>
#include "Consts.h"

class StepperLib {

private:
// char CHECK_PIN, STEP_PIN, EN_PIN, DIR_PIN, MS1_PIN, MS2_PIN, SPEED_PIN, ALARM_PIN;
TMC2209* driver;
Consts* consts;


public:
  StepperLib(Consts* consts_) : consts(consts_){
    driver = new TMC2209( );
   };

void setPinMode() {
  pinMode(consts->getCheckPin(), INPUT);
  pinMode(consts->getStepPin(), OUTPUT);
  pinMode(consts->getEnPin(), OUTPUT);
  pinMode(consts->getDirPin(), OUTPUT);
  pinMode(consts->getMs1Pin(), OUTPUT);
  pinMode(consts->getMs2Pin(), OUTPUT);
  pinMode(consts->getAlarmPin(), OUTPUT);
}

void setPinState(char EN_PIN_STATE, char DIR_PIN_STATE, char MS1_PIN_STATE, char MS2_PIN_STATE) {
  digitalWrite(consts->getCheckPin(), HIGH);
  digitalWrite(consts->getStepPin(), LOW);
  digitalWrite(consts->getEnPin(), EN_PIN_STATE);
  digitalWrite(consts->getDirPin(), DIR_PIN_STATE);
  digitalWrite(consts->getMs1Pin(), MS1_PIN_STATE);
  digitalWrite(consts->getMs2Pin(), MS2_PIN_STATE);
  digitalWrite(consts->getAlarmPin(), LOW);
}

void setUART(){

  SoftwareSerial driverSerial(consts->getRxPin(),consts->getTxPin());
  driverSerial.begin(115200);

  driver->setup(driverSerial, 115200, consts->getMotorUnit());
  
  driver->setMicrostepsPerStep(16);
  driver->setRMSCurrent(800, 0.11f);
  driver->enableStealthChop();
  driver->setStandstillMode(TMC2209::NORMAL);

  consts->setDriver(driver);

//   // // driver->enable();
//   // driver->moveAtVelocity(int32_t microsteps_per_period)
//   // driver->disable();

}

bool isDriverUnitEnabled(){
    return consts->getDriverUnitEnableStatus();
  }
};