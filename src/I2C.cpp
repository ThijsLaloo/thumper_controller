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

#include "lib/I2C.h"

//.c_str()

namespace touchberry{

	I2C::I2C(char addr){

		sprintf(filename,"/dev/i2c-1");
		if ((file = open(filename,O_RDWR)) < 0) {
				printf("Failed to open the bus.");
				/* ERROR HANDLING; you can check errno to see what went wrong */
				exit(1);
		}

		if (ioctl(file,I2C_SLAVE,addr) < 0) {
				printf("Failed to acquire bus access and/or talk to slave.\n");
				/* ERROR HANDLING; you can check errno to see what went wrong */
				exit(1);
		}

	}

	void I2C::PutI2C(char buf[], int bufsize){
		if (write(file,buf,bufsize) != bufsize) {
	    /* ERROR HANDLING: i2c transaction failed */
	    printf("Failed to write to the i2c bus.\n");
	    //buffer = g_strerror(errno);
	    //printf(buffer);
	    printf("\n\n");
		}
	}

	void I2C::GetI2C(char buf[], int bufsize){

		PutI2C(buf,1);

		if (read(file,buf,bufsize) != bufsize) {
	      /* ERROR HANDLING: i2c transaction failed */
	      printf("Failed to read from the i2c bus.\n");
	      //buffer = g_strerror(errno);
	      //printf(buffer);
	      printf("\n\n");
	  } else {
	      //return buf;
	  }
	}
}
