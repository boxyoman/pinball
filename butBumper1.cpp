#include "butBumper1.h"

pButBumper1::pButBumper1(pGame &game){
	this->game = game;
}

void pButBumper1::onActive(){
	game.outputs[outBumper1].activate();
}