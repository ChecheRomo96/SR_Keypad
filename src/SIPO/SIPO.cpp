#include "SIPO.h"
#include <stdint.h>

SR_Keypad::SIPO::SIPO(){
    _DataController = nullptr;
    _ClockController = nullptr;
    _LatchController = nullptr;
};

SR_Keypad::SIPO::SIPO(
    void (&DataController)(bool),
    void (&ClockController)(),
    void (&LatchController)()
) {
    _DataController = DataController;
    _ClockController = ClockController;
    _LatchController = LatchController;
}

void SR_Keypad::SIPO::Write(uint8_t Data){
    
    for(uint8_t i = 0; i < 8; i++){
        if(_DataController){_DataController((Data>>i)&0b1);}
        if(_ClockController){_ClockController();}
    }

    if(_LatchController){_LatchController();}
}

void SR_Keypad::SIPO::Write(uint8_t* Data, uint8_t len){

    for(uint8_t i = 0; i < len*8; i++){
        if(_DataController){_DataController((Data[i/8]>>(i%8))&0b1);}
        if(_ClockController){_ClockController();}
    }

    if(_LatchController){_LatchController();}
}
