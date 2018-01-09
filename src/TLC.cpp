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

#include "lib/TLC.h"
#include "lib/I2C.h"

namespace touchberry{

  TLC::TLC():i2c(0x60){

    buf[0] = 0x00;
    buf[1] = 0b00000001;
    i2c.PutI2C(buf,2);


    buf[1] = 0xaa;


    for (char k = 0x14; k <= 0x17; k++) {
      buf[0] = k;
      i2c.PutI2C(buf,2);
    }

  }

  void TLC::LEDFade(int i){
  	buf[0] = 0x04;
  	buf[1] = i;

  	i2c.PutI2C(buf,2);

    usleep(5000);
  }


  void TLC::ZeroLED(void){
  	for (size_t i = 0; i < 15; i++) {
  		buf[0] = i + 2;
  		buf[1] = 0x00;

  		i2c.PutI2C(buf,2);

  	  usleep(500);
  	}
  }


  void TLC::LEDLoop(void) {
    buf[1] = 0xff;

    for (int i = 0; i < 6; i++) {
      buf[0] = 2 + i * 3;

      i2c.PutI2C(buf,2);

      usleep(100000);
    }

  }

}
