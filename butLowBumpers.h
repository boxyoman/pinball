#ifndef butFlickup_h
#define butFlickup_h

#include "button.h"
#include "game.h"

class pButLowBumperRight : public pButton{
	pGame &game;
	
	public:
		pButLowBumperRight(pGame &_game) : game(_game), pButton(33, 70, HIGH){};
		void onActive();
		
};

class pButLowBumperLeft : public pButton{
	pGame &game;
	
	public:
		pButLowBumperLeft(pGame &_game) : game(_game), pButton(31, 70, HIGH){};
		void onActive();
		
};

#endif