#ifndef butBumper1_h
#define butBumper1_h

#include "button.h"
#include "game.h"

class pButBumper1 : public pButton{
	privite:
		pGame &game;
	public:
		pButBumper1(pGame &game) : pButton(47, 70, HIGH);
		void onActive();
		
};

#endif