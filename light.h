#ifndef light_h
#define light_h

#include "Arduino.h"

enum{
	litBumper1,
	litBumper2,
	litBumper3,
	litTarget1, 
	litTarget2,
	litTarget3,
	litLowBumperLeft,
	litLowBumperRight,
	numOfLights
};

class pLight{
	int pin;
	bool activeState;
	public:
		pLight(){};
		pLight(int pin, bool state, bool activeState);
		void lightOn();
		void lightOff();
		

};

#endif
