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
	ballCount = 5;
	
	/*buttons[butBumper1] = pButBumper1(*this);
	buttons[butBumper2] = pButBumper2(*this);
	buttons[butBumper3] = pButBumper3(*this);
	buttons[butDropTargets] = pButDropTargets(*this);
	buttons[butFlickup] = pButFlickup(*this);*/
	buttons[butReturnBall] = pButReturnBall(*this);
	//buttons[butBallReturned] = pButBallReturned(*this);
	
	outputs[outBumper1] = pOutBumper1();
	outputs[outBumper2] = pOutBumper2();
	outputs[outBumper3] = pOutBumper3();
	outputs[outDropTargets] = pOutDropTargets();
	outputs[outFlickUp] = pOutFlickUp();
	outputs[outReturnBall] = pOutReturnBall();
	
}

void pGame::loop(){
	//loop through outputs
	for(int i=0; i<numOfOutputs; i++){
		outputs[i].loop();
	}
	//loop through buttons
	buttons[butReturnBall].loop();
	/*for(int i=0; i<numOfButtons; i++){
		buttons[i].loop();
	}*/
}
