#ifndef MY_SIPO_H
#define MY_SIPO_H

  #include <SR_Keypad.h>

  #define SIPO_DATA_PIN  17
  #define SIPO_CLOCK_PIN 18
  #define SIPO_LATCH_PIN 19

  void SIPO_DataController(bool value);
  void SIPO_ClockController(void);
  void SIPO_LatchController(void);
  extern SR_Keypad::SIPO mySIPO;

#endif//MY_SIPO_H