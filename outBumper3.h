#ifndef outBumper3_h
#define outBumper3_h

#include "outputs.h"
#include "game.h"

class pOutBumper3 : public pOutputs{
	pGame &game;
	public:
		pOutBumper3(pGame &g) : game(g), pOutputs(46, 70, 0, LOW){};
};

#endif