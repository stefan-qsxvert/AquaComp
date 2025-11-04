#pragma once

#include "StepperLib.h"
#include "Arduino.h"
#include "Consts.h"
#include "Core.h"
#include "TMC2209.h"

class StepperBuilder{

private:
	Core* core;
	StepperLib* lib;
	// char lvl_pin, step_pin, enable_pin, direct_pin, ms1_pin, ms2_pin, speed_pin, alarm_pin;
	unsigned long priv_micros;
	Consts* consts;
	TMC2209* driver;

public:
  StepperBuilder(Consts* consts_) : consts(consts_){
			lib = new StepperLib(consts_);
			core = new Core();
			driver = consts_->getDriver();
		};
			
	void stepp(){

		driver->moveAtVelocity(analogRead(consts->getSpeedPin()));
		
		// driver->enable();

	// 	if (core->microsPeriod(priv_micros, 1024 - (analogRead(consts->getSpeedPin()) + 64))){
  //   	if (core->microsPeriod(priv_micros,32)){
  //   		Serial.println("ON");
  //   		priv_micros = micros();
  //   	}
  //   if (core->microsPeriod(priv_micros,32)){
  //   	Serial.println("OF");
  //   	priv_micros = micros();
  // 	}
	// }
}

	void setRunable(){
		if(!lib->isDriverUnitEnabled()){
      consts->getDriver()->enable();
      consts->setDriverUnitEnableStatus(true);
    } 
	}

	void load_settings(char EN_PIN_STATE, char DIR_PIN_STATE, char MS1_PIN_STATE, char MS2_PIN_STATE, char RX, char TX) {
		lib->setUART();
		lib->setPinMode();
		lib->setPinState( EN_PIN_STATE,  DIR_PIN_STATE,  MS1_PIN_STATE,  MS2_PIN_STATE);
	}
};