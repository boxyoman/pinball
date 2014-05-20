#include "outputs.h"

void pOutDropTargets::onActive(){
	game.dropTargetsDown = false;
}

void pOutBumper1::onActive(){
	game.score->add(1);
}

void pOutBumper2::onActive(){
	game.score->add(1);
}

void pOutBumper3::onActive(){
	game.score->add(1);
}