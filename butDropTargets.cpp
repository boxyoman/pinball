#include "butDropTargets.h"

void pButDropTargets::onActive(){
	Serial.write("drop targets down\n");
	game.dropTargetsDown = true;
	if (game.dropTargetAbility){
		game.outputs[outDropTargets]->activate();
	}
}
