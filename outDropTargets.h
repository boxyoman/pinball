#ifndef outDropTargets_h
#define outDropTargets_h

#include "outputs.h"
#include "game.h"

class pOutDropTargets : public pOutputs{
	public:
		pGame &game;
		pOutDropTargets(pGame &g) : game(g), pOutputs(44, 70, 500, LOW){};
		void onActive();
};

#endif