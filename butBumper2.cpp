#include "butBumper2.h"

pButBumper2::pButBumper2(pGame &game){
	this->game = game;
}

void pButBumper2::onActive(){
	game.outputs[outBumper2].activate();
}