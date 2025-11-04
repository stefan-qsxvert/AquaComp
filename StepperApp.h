 #pragma once

 #include "StepperBuilder.h"
//  #include "TMC2209.h"
 #include "Consts.h"
 #include "StepperLib.h"

class StepperApp {

private:
StepperBuilder* builder;
Core* core;
// StepperLib* lib;

char CHECK_pin, step_pin, enable_pin, direct_pin, ms1_pin, ms2_pin, speed_pin, alarm_pin;

Consts* consts;

unsigned long P = 0;

public:
  StepperApp(Consts* consts_) : consts(consts_){
    builder = new StepperBuilder(consts);
    core = new Core();
    // lib = new StepperLib(consts);
  };

  void load_setup(char EN_PIN_STATE, char DIR_PIN_STATE, char MS1_PIN_STATE, char MS2_PIN_STATE){
    builder->load_settings( EN_PIN_STATE,  DIR_PIN_STATE,  MS1_PIN_STATE,  MS2_PIN_STATE, consts->getRxPin(), consts->getTxPin());
  }

  void constantRun(){
    builder->setRunable();
    builder->stepp();
  }

  void conditionalRun(){
    if (core->period(P, 5000) && core->isPinLOW(CHECK_pin)){
      builder->setRunable();
      builder->stepp();
    }else if (consts->getDriverUnitEnableStatus()){
      consts->setDriverUnitEnableStatus(false);
      consts->getDriver()->disable();
    }

  }
};