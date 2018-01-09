#include <iostream>
#include <cstdio>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>

#include "lib/QT1070.h"
#include "lib/I2C.h"

namespace touchberry{

  QT1070::QT1070():i2c2(0x1B),thumper(){
  }


  void QT1070::ID(void) {
    buf[0] = 0x00;
    i2c2.GetI2C(buf,1);
    printf("Chip-id is: 0x%02x\n",buf[0]);
  }

  void QT1070::KEYS(void) {
    buf[0] = 0x03;
    i2c2.GetI2C(buf,1);

    Key key = (Key)buf[0];

      switch (key) {
        case LEFT:
          std::cout << "LEFT" << std::endl;
          thumper.Speed(150, -150);
          break;
        case RIGHT:
          std::cout << "RIGHT" << std::endl;
          thumper.Speed(-150, 150);
          break;
        case UP:
          std::cout << "UP" << std::endl;
          thumper.Speed(150, 150);
          break;
        case DOWN:
          std::cout << "DOWN" << std::endl;
          thumper.Speed(-150, -150);
          break;
        case A:
          std::cout << "A" << std::endl;
          thumper.Neo();
          break;
        case B:
          std::cout << "B" << std::endl;
          thumper.Battery();
          break;
        case X:
          std::cout << "X" << std::endl;
          thumper.NeoBlink();
          break;
        default:
          thumper.Speed(0, 0);
          break;
      }
  }


  void QT1070::CAL(void) {
    buf[0] = 56;
    buf[1] = 0xff;
    i2c2.PutI2C(buf,2);

    buf[0] = 0x02;

    i2c2.GetI2C(buf,1);
    printf("cal is: 0x%02x\n",buf[0]);

    while (buf[0] == 0x80){
      buf[0] = 0x02;

      i2c2.GetI2C(buf,1);
      printf("Still calibrating\n");
    }

    printf("Calibrating done!\n");

  }
}
