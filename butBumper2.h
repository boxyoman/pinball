#ifndef butBumper2_h
#define butBumper2_h

#include "button.h"
#include "game.h"

class pButBumper2 : public pButton{
	pGame &game;
	
	public:
		pButBumper2(pGame &_game) : game(_game), pButton(51, 70, HIGH){};
		void onActive();
		
};

#endif