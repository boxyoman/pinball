#include "light.h"

pLight::pLight(int pin, bool state , bool activeState){
	pinMode(pin, OUTPUT);
	this->pin = pin;
	this->activeState = activeState;
	if (state){
		digitalWrite(pin, activeState);
	}else{
		digitalWrite(pin, !activeState);
	}
}

void pLight::lightOn(){
	digitalWrite(pin, activeState);
}

void pLight::lightOff(){
	digitalWrite(pin, !activeState);
}