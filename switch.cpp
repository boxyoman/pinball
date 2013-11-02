#include "switch.h"

pSwitch::pSwitch(){
	this->pinNum = 52;
	this->onTime = 100;
	this->delayTime = 100;
	this->activeState = HIGH;
	setup();
}

pSwitch::pSwitch(int pinNum, int onTime, int delayTime){
	this->pinNum = pinNum;
	this->onTime = onTime;
	this->delayTime = delayTime;
	this->activeState = HIGH;
	setup();
}

pSwitch::pSwitch(int pinNum, int onTime, int delayTime, bool activeState){
	this->activeState = activeState;
	this->delayTime = delayTime;
	this->pinNum = pinNum;
	this->onTime = onTime;
	setup();
}

void pSwitch::setup(){
	pinMode(pinNum, OUTPUT);
	state = (activeState==LOW)?HIGH:LOW;
	digitalWrite(pinNum, state);
	this->startTime = 0;
	switchState = swOff;
}

void pSwitch::avtivate(){
	if(switchState == swOff){
		this->state = this->activeState;
		switchState = swInDelay;
		startTime = millis();
	}
}

void pSwitch::loop(){
	//keep switch on until time runs out
	if(startTime != 0){
		unsigned long eTime = millis() - startTime;
		if(eTime >= delayTime && switchState == swInDelay){
			digitalWrite(pinNum, activeState);
			switchState = swOn;
		}
		if(eTime >= onTime+delayTime && switchState == swOn){
			switchState = swOff;
			state = (activeState==LOW)?HIGH:LOW;
			digitalWrite(pinNum, state);
			startTime = 0;
		}
	}
}
