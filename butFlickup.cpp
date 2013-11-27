#include "butFlickup.h"

pButFlickup::pButFlickup(pGame &game){
	this->game = game;
}

void pButFlickup::onActive(){
	game.outputs[outFlickUp].activate();
}