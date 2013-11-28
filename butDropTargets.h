#ifndef butDropTargets_h
#define butDropTargets_h

#include "button.h"
#include "game.h"

class pButDropTargets : public pButton{
	pGame &game;
	
	public:
		pButDropTargets(pGame &_game) : game(_game), pButton(45, 200, HIGH){};
		void onActive();
		
};

#endif