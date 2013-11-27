#ifndef butBumper3_h
#define butBumper3_h

#include "button.h"
#include "game.h"

class pButBumper3 : public pButton{
	pGame &game;
	
	public:
		pButBumper3(pGame &_game) : game(_game), pButton(49, 1, HIGH){};
		void onActive();
		
};

#endif