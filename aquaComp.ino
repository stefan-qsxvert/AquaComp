#include "RefillApp.h"
#include "StepperApp.h"
#include "TMC2209.h"
// #include "Consts.h"
#include "StepperBuilder.h"


#define HS 8
#define LS 6
#define P0 3
#define P1 4

#define lvl_pin 6
#define step_pin 3
#define enable_pin 4
#define direct_pin 2
#define ms1_pin 9
#define ms2_pin 8
#define speed_pin 1
#define alarm_pin 12
#define RX_PIN 99
#define TX_PIN 99

  RefillApp* rapp = new RefillApp(HS, LS, P0, P1);
  // StepperApp* reaktor0 = new StepperApp(lvl_pin, step_pin, enable_pin, direct_pin, ms1_pin, ms2_pin, speed_pin, alarm_pin; TMC::SERIAL_ADDRESS_0);
  // StepperApp* reaktor1 = new StepperApp(lvl_pin, step_pin, enable_pin, direct_pin, ms1_pin, ms2_pin, speed_pin, alarm_pin, TMC::SERIAL_ADDRESS_1);
  // StepperApp* roller = new StepperApp(lvl_pin, step_pin, enable_pin, direct_pin, ms1_pin, ms2_pin, speed_pin, alarm_pin, TMC::SERIAL_ADDRESS_2);

  //onsts(char CHECK_PIN_, char STEP_PIN_, char EN_PIN_, char DIR_PIN_, char MS1_PIN_, char MS2_PIN_, char SPEED_PIN_, char ALARM_PIN_, char RX_, char TX_)

  Consts* unit0 = new Consts(lvl_pin, step_pin, enable_pin, direct_pin, ms1_pin, ms2_pin, speed_pin, alarm_pin, RX_PIN, TX_PIN, TMC2209::SERIAL_ADDRESS_0);
  Consts* unit1 = new Consts(lvl_pin, step_pin, enable_pin, direct_pin, ms1_pin, ms2_pin, speed_pin, alarm_pin, RX_PIN, TX_PIN, TMC2209::SERIAL_ADDRESS_1);
  Consts* unit2 = new Consts(lvl_pin, step_pin, enable_pin, direct_pin, ms1_pin, ms2_pin, speed_pin, alarm_pin, RX_PIN, TX_PIN, TMC2209::SERIAL_ADDRESS_2);

  StepperApp* reaktor0 = new StepperApp(unit0);
  StepperApp* reaktor1 = new StepperApp(unit1);
  StepperApp* roller = new StepperApp(unit2);

void setup() {
  Serial.begin(9600 );

  rapp->load_setup();

  reaktor0->load_setup(HIGH, LOW, LOW, LOW);
  reaktor1->load_setup(HIGH, LOW, HIGH, LOW);
  roller->load_setup(HIGH, LOW, LOW, HIGH);

  Serial.println("GOT IT!");
}

void loop() {
  rapp->run();
  reaktor0->constantRun();
  reaktor1->constantRun();
  roller->conditionalRun();
}