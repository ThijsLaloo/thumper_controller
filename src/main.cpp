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
#include "lib/QT1070.h"

// int file;
// char filename[40];

char buf[1] = {0x00};

using namespace touchberry;

int main(void) {
	std::cout << "Touchberry Super3000" << std::endl;

	TLC tlc;
	QT1070 qt1070;

	qt1070.ID();
	qt1070.CAL();

	while (1) {
		/*tlc.LEDLoop();
		tlc.ZeroLED();*/
		//usleep(100000);
		qt1070.KEYS();
		usleep(200000);
	}


	return 0;
}
