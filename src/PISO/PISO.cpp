#include "PISO.h"


SR_Keypad::PISO::PISO(){
    _DataController = nullptr;
    _ClockController = nullptr;
    _SLController = nullptr;
}

SR_Keypad::PISO::PISO(
    bool (&DataController)(),
    void (&ClockController)(),
    void (&SLController)()
){
    _DataController = DataController;
    _ClockController = ClockController;
    _SLController = SLController;
}

uint8_t SR_Keypad::PISO::Read(uint8_t bits){

    uint8_t output = 0;

    if(_SLController){_SLController();}

    for(uint8_t i = 0; i < bits; i++){
        bool data = 0;
        if(_DataController){
            data = _DataController();
            output |= (data << i);
        }

        if(_ClockController){_ClockController();}
    }

    return output;
}

uint8_t* SR_Keypad::PISO::ReadArray(uint8_t bytes, uint8_t* buffer){

    if(_SLController){_SLController();}

    for(uint8_t i = 0; i < bytes * 8; i++){
        buffer[i/8] = 0;
        if(_DataController){
            buffer[i/8] |= (_DataController()<<i);
        }

        if(_ClockController){_ClockController();}
    }

    return buffer;
}