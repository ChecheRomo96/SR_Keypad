#ifndef SR_KEYPAD_SIPO_H
#define SR_KEYPAD_SIPO_H

    #include <stdint.h>

    namespace SR_Keypad{

        class SIPO{
            private: 
                // Apuntadores a funciones
                void(*_DataController)(bool);
                void(*_ClockController)(void);
                void(*_LatchController)(void);
            
            public:

                SIPO();

                SIPO(
                    void (&DataController)(bool),
                    void (&ClockController)(),
                    void (&LatchController)()
                );

                void Write(uint8_t Data);
                void Write(uint8_t* Data, uint8_t len);
            
        };
    }

#endif//SR_KEYPAD_SIPO_H