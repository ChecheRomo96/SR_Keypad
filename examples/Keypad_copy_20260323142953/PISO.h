#ifndef MY_PISO_H
#define MY_PISO_H

  #include <SR_Keypad.h>

  #define PISO_DATA_PIN   4
  #define PISO_CLOCK_PIN  3
  #define PISO_SL_PIN     2

  bool PISO_DataController();
  void PISO_ClockController(void);
  void PISO_SLController(void);
  extern SR_Keypad::PISO myPISO;

#endif//MY_PISO_H