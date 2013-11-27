#include "butBumper3.h"

pButBumper3::pButBumper3(pGame &game){
	this->game = game;
}

void pButBumper3::onActive(){
	game.outputs[outBumper3].activate();
}