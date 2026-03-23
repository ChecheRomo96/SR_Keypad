#ifndef SR_KEYPAD_CONTROLLER_H
#define SR_KEYPAD_CONTROLLER_H

    #include <stdint.h>

    #include "../SIPO/SIPO.h"
    #include "../PISO/PISO.h"

    namespace SR_Keypad{

        class Controller{
            public:

            enum StatusKeys : uint8_t{
                Rising      = 0b00,
                Falling     = 0b01,
                IdleHigh    = 0b10,
                IdleLow     = 0b11
            };

            private:

                SIPO* _out_controller;
                PISO* _in_controller;

                uint8_t _prev_states[8];

                void(*_Callback)(uint8_t ID, bool State);
        
            public:

                Controller();
                Controller(void(&Callback)(uint8_t ID, bool State));

                void AttachCallback(void(&Callback)(uint8_t ID, bool State));
                void ClearCallback();

                void AttachSIPO(SIPO& SIPO_Controller);
                void DettachSIPO();

                void AttachPISO(PISO& PISO_Controller);
                void DettachPISO();


                void Scan();
                
        };

    }

#endif//SR_KEYPAD_CONTROLLER_H