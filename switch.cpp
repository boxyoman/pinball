#include "switch.h"

switch::switch(int pinNum, float onTime){
	this->pinNum = pinNum;
	this->onTime = onTime;
	this->activeState = HIGH;
	setup();
}

switch::switch(int pinNum, float onTime, bool activeState){
	this->activeState = activeState;
	this->pinNum = pinNum;
	this->onTime = onTime;
	setup();
}

void switch::setup(){
	pinMode(pinNum, OUTPUT);
	state = (activeState==LOW)?HIGH:LOW;
	digitalWrite(pinNum, state);
	startTime = 0;
}

void switch::loop(){
	//turn switch on
	if(state == activeState && startTime == 0){
		startTime = millis();
		digitalWrite(pinNum, state);
	}
	
	//keep switch on until time runs out
	if(startTime != 0){
		float eTime = millis() - startTime;
		if(eTime >= onTime){
			state = (activeState==LOW)?HIGH:LOW;
			digitalWrite(pinNum, state);
			startTime = 0;
		}
	}
}