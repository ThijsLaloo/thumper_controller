#pragma once

namespace touchberry{
    class I2C{
      private:

        int file;
        char filename[40];
        int bufsize;
        char buf[];
        //const char *buffer;

      public:
        I2C(char addr);
        void GetI2C(char buf[], int bufsize);
        void PutI2C(char buf[], int bufsize);
    };
}
