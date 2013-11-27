#ifndef butFlickup_h
#define butFlickup_h

#include "button.h"
#include "game.h"

class pButFlickup : public pButton{
	pGame &game;
	
	public:
		pButFlickup(pGame &_game) : game(_game), pButton(53, 70, HIGH){};
		void onActive();
		
};

#endif