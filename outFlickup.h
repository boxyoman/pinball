#ifndef outFlickup_h
#define outFlickup_h

#include "outputs.h"
#include "game.h"

class pOutFlickUp : public pOutputs{
	pGame &game;
	public:
		pOutFlickUp(pGame &g) : game(g), pOutputs(52, 70, 1000, LOW){};
};

#endif