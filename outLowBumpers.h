#ifndef outLowBumper_h
#define outLowBumper_h

#include "outputs.h"
#include "game.h"

class pOutLowBumberLeft : public pOutputs{
	pGame &game;
	public:
		pOutLowBumberLeft(pGame &g) : game(g), pOutputs(30, 70, 0, LOW){};
};

class pOutLowBumberRight : public pOutputs{
	pGame &game;
	public:
		pOutLowBumberRight(pGame &g) : game(g), pOutputs(32, 70, 0, LOW){};
};

#endif