#pragma once
#include "I2C.h"
#include "Thumper.h"

namespace touchberry{
    class QT1070{
      private:
        I2C i2c2;
        THUMPER thumper;
        char buf[];
        enum Key {LEFT = 0x01,
            RIGHT = 0x02,
            UP = 0x04,
            DOWN = 0x08,
            B = 0x10,
            A = 0x20,
            X = 0x40};

      public:
        QT1070();
        void ID(void);
        void KEYS(void);
        void CAL(void);
    };
}
