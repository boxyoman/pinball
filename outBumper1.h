#ifndef outBumper1_h
#define outBumper1_h

#include "outputs.h"
#include "game.h"

class pOutBumper1 : public pOutputs{
	pGame &game;
	public:
		pOutBumper1(pGame &g) : game(g), pOutputs(48, 70, 0, LOW){};
};

#endif