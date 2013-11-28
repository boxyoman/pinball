#include "outDropTargets.h"

void pOutDropTargets::onActive(){
	Serial.write("reset drop targets\n");
	game.dropTargetsDown = false;
}