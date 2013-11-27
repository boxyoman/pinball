#include "game.h"
#include "butBumper1.h"
#include "butBumper2.h"
#include "butBumper3.h"
#include "butDropTargets.h"
#include "butFlickup.h"
#include "outBallReturn.h"
#include "outBumper1.h"
#include "outBumper2.h"
#include "outBumper3.h"
#include "outDropTargets.h"
#include "outFlickup.h"

void pGame::setup(){
	//initialize game here
	buttons[butBumper1] = pButBumper1(*this);
	buttons[butBumper2] = pButBumper2(*this);
	buttons[butBumper3] = pButBumper3(*this);
	buttons[butDropTargets] = pButDropTargets(*this);
	buttons[butFlickup] = pButFlickup(*this);
	
	outputs[outBumper1] = pOutBumper1();
	outputs[outBumper2] = pOutBumper2();
	outputs[outBumper3] = pOutBumper3();
	outputs[outDropTargets] = pOutDropTargets();
	outputs[outFlickUp] = pOutFlickUp();
	
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
