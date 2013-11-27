#include "game.h"

void pGame::setup(){
	//initialize game here
	
	
}

void pGame::loop(){
	//loop through outputs
	for(int i=0; i<numOfOutputs; i++){
		outputs[i].loop();
	}
	//loop through buttons
	for(int i=0; i<numOfButtons; i++){
		buttons[i].loop();
	}
}