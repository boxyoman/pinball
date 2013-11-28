#include "butFlickup.h"

void pButFlickup::onActive(){
	game.outputs[outFlickUp]->activate();
	if (game.targetNum[0] && game.targetNum[1] && game.targetNum[0] && game.targetNum[2] && game.dropTargetsDown){
		game.outputs[outDropTargets]->activate();
		game.dropTargetAbility = true;
		game.targetNum[0] = false;
		game.targetNum[1] = false;
		game.targetNum[2] = false;
		Serial.write("WINNER!!!!!!");
	}
}