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

#include "lib/Thumper.h"

std::string ip = "10.0.0.133";

namespace touchberry{

	THUMPER::THUMPER(){

	}

	void THUMPER::Speed(int left, int right){
		r = RestClient::post("http://" + ip + ":3000/speed" , "application/json", "{ \"left_speed\":" + std::to_string(left) + ", \"right_speed\":" + std::to_string(right) + "}");
	}

	void THUMPER::Neo(){
		r = RestClient::post("http://" + ip + ":3000/neopixels/strings/0", "application/json", "{ \"red\": 0, \"green\": 255, \"blue\": 0 }");
	}

	void THUMPER::NeoBlink(){
		r = RestClient::post("http://" + ip + ":3000/neopixels/strings/strobe/0", "application/json", "{ \"red\": 0, \"green\": 0, \"blue\": 255, \"delay\": 100 }");
	}

	void THUMPER::Battery(){
		r = RestClient::get("http://" + ip + ":3000/batteryvoltage");
		printf("%s \n", r.body.c_str());
	}


}
