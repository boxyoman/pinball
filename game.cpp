#include "game.h"
#include "butBumper1.h"
#include "butBumper2.h"
#include "butBumper3.h"
#include "butDropTargets.h"
#include "butFlickup.h"
#include "butReturnBall.h"
#include "butBallReturned.h"
#include "outBumper1.h"
#include "outBumper2.h"
#include "outBumper3.h"
#include "outDropTargets.h"
#include "outFlickup.h"
#include "outReturnBall.h"

void pGame::setup(){
	//initialize game here
	Serial.begin(9600);
	Serial.write("Started\n");
	
	ballCount = 5;
	
	buttons[butBumper1] = new pButBumper1(*this);
	buttons[butBumper2] = new pButBumper2(*this);
	buttons[butBumper3] = new pButBumper3(*this);
	buttons[butDropTargets] = new pButDropTargets(*this);
	buttons[butFlickup] = new pButFlickup(*this);
	buttons[butReturnBall] = new pButReturnBall(*this);
	buttons[butBallReturned] = new pButBallReturned(*this);
	
	outputs[outBumper1] = new pOutBumper1();
	outputs[outBumper2] = new pOutBumper2();
	outputs[outBumper3] = new pOutBumper3();
	outputs[outDropTargets] = new pOutDropTargets();
	outputs[outFlickUp] = new pOutFlickUp();
	outputs[outReturnBall] = new pOutReturnBall();
	
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
