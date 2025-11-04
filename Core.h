#pragma once

#include <Arduino.h>

class Core{

private:

public:
  Core() = default;

bool period(unsigned long P, unsigned long dif){
    return (millis() - P >= dif);
}

bool microsPeriod(unsigned long P, unsigned long dif){
    return (micros() - P >= dif);
}

bool isPinLOW(byte pin){
  return (digitalRead(pin) == LOW);
}

};