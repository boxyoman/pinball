#include "butLowBumpers.h"

void pButLowBumperRight::onActive(){
	game.outputs[butLowBumberRight]->activate();
}

void pButLowBumperLeft::onActive(){
	game.outputs[butLowBumberLeft]->activate();
}