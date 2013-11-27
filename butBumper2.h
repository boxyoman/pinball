#ifndef butBumper2_h
#define butBumper2_h

#include "button.h"
#include "game.h"

class pButBumper2 : public pButton{
	privite:
		pGame &game;
	public:
		pButBumper2(pGame &game) : pButton(51, 70, HIGH);
		void onActive();
		
};

#endif