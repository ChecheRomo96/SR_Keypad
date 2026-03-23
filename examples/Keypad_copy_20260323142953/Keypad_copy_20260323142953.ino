#include <SR_Keypad.h>
#include "SIPO.h"
#include "PISO.h"

void Callback(uint8_t id, bool state){
  if(state){
    Serial.println("Detected Rising Edge on button no. " + String(id));
  }
  else{
    Serial.println("Detected Falling Edge on button no. " + String(id));
  }
}

SR_Keypad::Controller myController(Callback);

void setup() {

  Serial.begin(115200);

  pinMode(PISO_DATA_PIN, INPUT);
  pinMode(PISO_CLOCK_PIN, OUTPUT);
  pinMode(PISO_SL_PIN, OUTPUT);
  pinMode(SIPO_DATA_PIN, OUTPUT);
  pinMode(SIPO_CLOCK_PIN, OUTPUT);
  pinMode(SIPO_LATCH_PIN, OUTPUT);

  myController.AttachSIPO(mySIPO);
  myController.AttachPISO(myPISO);
}

void loop() {
  myController.Scan();
  delay(300);
}
