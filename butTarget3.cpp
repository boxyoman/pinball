#include "butTarget3.h"

void pButTarget3::onActive(){
	Serial.write("Target 3 click\n");
	if (game.targetNum[1] == true && game.targetNum[2] == false){
		game.targetNum[2] = true;
		game.outputs[outDropTargets]->activate();
		game.dropTargetAbility = false;
		
	}
}
