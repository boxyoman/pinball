#include "butReturnBall.h"

void pButReturnBall::onActive(){
	Serial.write("pButReturnBall onActive\n");
	/*
	if (game.ballCount > 0){
		game.outputs[outReturnBall].activate();
		game.outputs[outDropTargets].activate();
	}
	*/
	
}
