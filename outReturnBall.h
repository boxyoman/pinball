#ifndef outBallReturn_h
#define outBallReturn_h

#include "outputs.h"
#include "game.h"

class pOutReturnBall : public pOutputs{
	pGame &game;
	public:
		pOutReturnBall(pGame &g) : game(g), pOutputs(42, 70, 1000, LOW){Serial.write("pOutReturnBall initialized\n");};
};

#endif
