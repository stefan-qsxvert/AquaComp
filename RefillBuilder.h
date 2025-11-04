#pragma once

#include "Core.h"
#include "RefillLib.h"
#include <Arduino.h>


class RefillBuilder{

private:
  char HS, LS, P0, P1;
  Core* core;
  RefillLib* lib;

public:
    RefillBuilder(char HS_, char LS_, char P0_, char P1_){
        LS = LS_;
        HS = HS_;
        P0 = P0_;
        P1 = P1_; 
      core = new Core();
      lib = new RefillLib(HS_, LS_, P0_, P1_);  
    };

  unsigned long p;

void setup(){
  lib->setPinMode();
  lib->setPinState();
}

void refill() {

    if (core->period(p, 5000)){

        if (core->isPinLOW(LS) && core->isPinLOW(P1)){
            digitalWrite(P1, HIGH );
            Serial.println("ON");
        }

        if (!core->isPinLOW(LS) && !core->isPinLOW(P1)) {
            digitalWrite(P1, LOW );
            Serial.println("OFF");
        }

        if (!core->isPinLOW(P1) && !core->isPinLOW(HS)) {
            digitalWrite(P1, LOW );
            Serial.println("OFF");
        }
        p = millis();
    }
}

void setP(unsigned long e){
  p = e;
}

unsigned long getP(){
  return p;
}
};
