#include "butReturnBall.h"

void pButReturnBall::onActive(){
	if (game.ballCount > 0){
		game.outputs[outReturnBall].activate();
		game.outputs[outDropTargets].activate();
	}
	
}
