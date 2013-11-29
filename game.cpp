#include "game.h"
#include "buttons.h"
#include "outputs.h"

void pGame::setup(){ //initialize game here
	
	Serial.begin(9600);
	Serial.write("Started\n");
	
	ballCount = 5;
	//target variables
	targetNum[0] = false;
	targetNum[1] = false;
	targetNum[2] = false;
	dropTargetAbility = true;
	dropTargetsDown = false;
	
	//initializing buttons
	buttons[butBumper1] = new pButBumper1(*this);
	buttons[butBumper2] = new pButBumper2(*this);
	buttons[butBumper3] = new pButBumper3(*this);
	buttons[butDropTargets] = new pButDropTargets(*this);
	buttons[butFlickup] = new pButFlickup(*this);
	buttons[butReturnBall] = new pButReturnBall(*this);
	buttons[butBallReturned] = new pButBallReturned(*this);
	buttons[butTarget1] = new pButTarget1(*this);
	buttons[butTarget2] = new pButTarget2(*this);
	buttons[butTarget3] = new pButTarget3(*this);
	buttons[butLowBumberRight] = new pButLowBumperRight(*this);
	buttons[butLowBumberLeft] = new pButLowBumperLeft(*this);
	
	//initializing outputs
	outputs[outBumper1] = new pOutBumper1(*this);
	outputs[outBumper2] = new pOutBumper2(*this);
	outputs[outBumper3] = new pOutBumper3(*this);
	outputs[outDropTargets] = new pOutDropTargets(*this);
	outputs[outFlickUp] = new pOutFlickUp(*this);
	outputs[outReturnBall] = new pOutReturnBall(*this);
	outputs[outLowBumperRight] = new pOutLowBumperRight(*this);
	outputs[outLowBumperLeft] = new pOutLowBumperLeft(*this);
	
}

void pGame::loop(){
	//loop through outputs
	for(int i=0; i<numOfOutputs; i++){
		outputs[i]->loop();
	}
	//loop through buttons
	for(int i=0; i<numOfButtons; i++){
		buttons[i]->loop();
	}
}
