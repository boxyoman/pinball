#ifndef switch_h
#define switch_h

#include "Arduino.h"

enum {
	bumper1,
	bumper2,
	bumper3,
	dropTarggets,
	targget2,
	targget3,
	flickUp,
	swReturnBall,
	numOfSwitches
};

typedef enum{
	swInDelay=0,
	swOn=1,
	swOff=2,
} switchStates;

class pSwitch{
public:
	pSwitch();
	pSwitch(int pinNum, int onTime, int delayTime);
	pSwitch(int pinNum, int onTime, int delayTime, bool activeState);
	int pinNum;
	int onTime; //the amount of time the switch should be on for(in milliseconds)
	int delayTime;
	bool state;
	bool activeState;
	switchStates switchState;
	void loop(); //call every tick
	void activate();
private:
	unsigned long startTime;
	void setup();
};

#endif
