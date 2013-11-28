#ifndef outBumper2_h
#define outBumper2_h

#include "outputs.h"
#include "game.h"

class pOutBumper2 : public pOutputs{
	pGame &game;
	public:
		pOutBumper2(pGame &g) : game(g), pOutputs(50, 70, 0, LOW){};
};

#endif