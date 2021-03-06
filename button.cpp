#include "button.h"

pButton::pButton(int pin, int onTime, bool activeState){
	pinMode(pin, INPUT);
	this->pin = pin;
	this->activeState = activeState;
	this->lastState = !activeState;
	this->onTime = onTime;
	this->startTime = 0;
	this->stateEqual = false;
	this->state = !activeState;
	this->letGo = true;
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
				if (letGo){
					this->onActive();
					letGo = false;
				}
				stateEqual = false;
			}
			
		}else{
			stateEqual = false;
		}
	}
	lastState = state;
	if (state != activeState){
		letGo = true;
	}
}