#ifndef outLowBumper_h
#define outLowBumper_h

#include "outputs.h"
#include "game.h"

class pOutLowBumperLeft : public pOutputs{
	pGame &game;
	public:
		pOutLowBumperLeft(pGame &g) : game(g), pOutputs(30, 70, 0, LOW){};
};

class pOutLowBumperRight : public pOutputs{
	pGame &game;
	public:
		pOutLowBumperRight(pGame &g) : game(g), pOutputs(32, 70, 0, LOW){};
};

#endif