#include "game.h"
#include "buttons.h"
#include "outputs.h"

void pGame::setup(){ //initialize game here
	
	Serial.begin(9600);
	Serial.write("Started\n");
	
	ballCount = 0;
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
	buttons[butLowBumperRight] = new pButLowBumperRight(*this);
	buttons[butLowBumperLeft] = new pButLowBumperLeft(*this);
	buttons[butStart] = new pButStart(*this);

	
	//initializing outputs
	outputs[outBumper1] = new pOutBumper1(*this);
	outputs[outBumper2] = new pOutBumper2(*this);
	outputs[outBumper3] = new pOutBumper3(*this);
	outputs[outDropTargets] = new pOutDropTargets(*this);
	outputs[outFlickUp] = new pOutFlickUp(*this);
	outputs[outReturnBall] = new pOutReturnBall(*this);
	outputs[outLowBumperRight] = new pOutLowBumperRight(*this);
	outputs[outLowBumperLeft] = new pOutLowBumperLeft(*this);
	
	//initializing lights
	lights[litBumper1] = new pLight(12, HIGH, HIGH);
	lights[litBumper2] = new pLight(11, HIGH, HIGH);
	lights[litBumper3] = new pLight(10, HIGH, HIGH);
	lights[litTarget1] = new pLight(9, HIGH, HIGH);
	lights[litTarget2] = new pLight(8, HIGH, HIGH);
	lights[litTarget3] = new pLight(7, HIGH, HIGH);
	lights[litLowBumperLeft] = new pLight(6, HIGH, HIGH);
	lights[litLowBumperRight] = new pLight(5, HIGH, HIGH);
	
	//initialize the scorewheels
	score = new pScore(*this);
	
	//function to put arduino into the start of a game
	resetLoop();
	
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
	score->loop();
}

void pGame::resetLoop(){
	while (ballCount == 0){
		buttons[butStart]->loop();
	}
}

void pGame::reset(){
	ballCount = 5;
	//target variables
	targetNum[0] = false;
	targetNum[1] = false;
	targetNum[2] = false;
	dropTargetAbility = true;
	dropTargetsDown = false;
	outputs[outReturnBall]->activate();
	outputs[outDropTargets]->activate();
}
