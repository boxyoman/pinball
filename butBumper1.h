#ifndef butBumper1_h
#define butBumper1_h

#include "button.h"
#include "game.h"

class pButBumper1 : public pButton{
	pGame &game;
	public:
		pButBumper1(pGame &_game) : game(_game), pButton(47, 1, HIGH){};
		void onActive();
		
};

#endif
