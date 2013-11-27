#ifndef butDropTargets_h
#define butDropTargets_h

#include "button.h"
#include "game.h"

class pButDropTargets : public pButton{
	privite:
		pGame &game;
	public:
		pButDropTargets(pGame &game) : pButton(45, 70, HIGH);
		void onActive();
		
};

#endif