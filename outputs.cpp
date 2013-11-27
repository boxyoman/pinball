#include "switch.h"

pOutputs::pOutputs(){
	this->pinNum = 52;
	this->onTime = 100;
	this->delayTime = 100;
	this->activeState = HIGH;
	setup();
}

pOutputs::pOutputs(int pinNum, int onTime, int delayTime){
	this->pinNum = pinNum;
	this->onTime = onTime;
	this->delayTime = delayTime;
	this->activeState = HIGH;
	setup();
}

pOutputs::pOutputs(int pinNum, int onTime, int delayTime, bool activeState){
	this->activeState = activeState;
	this->delayTime = delayTime;
	this->pinNum = pinNum;
	this->onTime = onTime;
	setup();
}

void pOutputs::setup(){
	pinMode(pinNum, OUTPUT);
	state = (activeState==LOW)?HIGH:LOW;
	digitalWrite(pinNum, state);
	this->startTime = 0;
	switchState = swOff;
}

void pOutputs::activate(){
	if(switchState == swOff){
		onActive();
		this->state = this->activeState;
		switchState = swInDelay;
		startTime = millis();
	}
}

void pOutputs::loop(){
	//keep switch on until time runs out
	if(startTime != 0){
		unsigned long eTime = millis() - startTime;
		if(eTime >= delayTime && switchState == swInDelay){
			digitalWrite(pinNum, activeState);
			switchState = swOn;
		}
		if(eTime >= onTime+delayTime && switchState == swOn){
			onDeavtive();
			switchState = swOff;
			state = (activeState==LOW)?HIGH:LOW;
			digitalWrite(pinNum, state);
			startTime = 0;
		}
	}
}
