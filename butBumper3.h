#ifndef butBumper3_h
#define butBumper3_h

#include "button.h"
#include "game.h"

class pButBumper3 : public pButton{
	privite:
		pGame &game;
	public:
		pButBumper3(pGame &game) : pButton(49, 70, HIGH);
		void onActive();
		
};

#endif