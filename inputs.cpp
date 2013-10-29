#include "inputs.h"

input::input(int pinNum){
	this->pinNum = pinNum;
	activeState = HIGH;
	button = Button(pinNum, activeState);
}

input::input(int pinNum, int activeState){
	this->pinNum = pinNum;
	this->activeState = activeState;
	button = Button(pinNum, activeState);
}

void input::check(){
	if(button.onPress()){
		button.listen();
		trigger();
	}
}

void input::trigger(){}

input::~input(){
	delete button;
}