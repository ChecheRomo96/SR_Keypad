#include "PISO.h"
#include <Arduino.h>

bool PISO_DataController(){
  return digitalRead(PISO_DATA_PIN);
}

void PISO_ClockController(void){
  digitalWrite(PISO_CLOCK_PIN,1);
  digitalWrite(PISO_CLOCK_PIN,0);
}

void PISO_SLController(void){
  digitalWrite(PISO_SL_PIN,1);
  digitalWrite(PISO_SL_PIN,0);
}

SR_Keypad::PISO myPISO(
  PISO_DataController,
  PISO_ClockController,
  PISO_SLController
);