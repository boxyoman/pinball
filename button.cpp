#include "button.h"

pButton::pButton(){}

pButton::pButton(int pin, int onTime, bool activeState){
	pinMode(pin, INPUT);
	this->pin = pin;
	this->activeState = activeState;
	this->lastState = !activeState;
	this->onTime = onTime;
	this->startTime = 0;
	this->stateEqual = false;
	this->state = !activeState;
}

void pButton::loop(){
	state = digitalRead(pin);
	unsigned long eTime = millis() - startTime;
	if (!stateEqual){
		if(state == activeState){
			if (lastState == state){
				stateEqual = true;
				startTime = millis();
			}
		}
	}else{
		if(lastState == state){
			if (eTime > onTime){
				onActive();
				stateEqual = false;
			}
			
		}else{
			stateEqual = false;
		}
	}
	lastState = state;
}