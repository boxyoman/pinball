#ifndef butFlickup_h
#define butFlickup_h

#include "button.h"
#include "game.h"

class pButFlickup : public pButton{
	privite:
		pGame &game;
	public:
		pButFlickup(pGame &game) : pButton(53, 70, HIGH);
		void onActive();
		
};

#endif