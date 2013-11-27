#include "butDropTargets.h"

pButDropTargets::pButDropTargets(pGame &game){
	this->game = game;
}

void pButDropTargets::onActive(){
	game.outputs[outDropTarggets].activate();
}