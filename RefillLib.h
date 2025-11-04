#pragma once

#include <Arduino.h>
#include "Core.h"

class RefillLib {

private:
char LS, HS, P0, P1;
Core* core;

public:

    RefillLib(char HS_, char LS_, char P0_, char P1_){
        LS = LS_;
        HS = HS_;
        P0 = P0_;
        P1 = P1_;
        
        core = new Core();
    };

void setPinMode() {
  pinMode(LS, INPUT);
  pinMode(HS, INPUT);
  pinMode(P0, OUTPUT);
  pinMode(P1, OUTPUT);
}

void setPinState() {
  digitalWrite(LS, HIGH);
  digitalWrite(HS, HIGH);
  digitalWrite(P0, LOW);
  digitalWrite(P1, LOW);
}


};