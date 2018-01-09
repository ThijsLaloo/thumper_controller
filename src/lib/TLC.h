#pragma once
#include "I2C.h"

namespace touchberry{
    class TLC{
      private:
        I2C i2c;
        char buf[];

      public:
        TLC();
        void ZeroLED(void);
        void LEDLoop(void);
        void LEDFade(int i);
    };
}
