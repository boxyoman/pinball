#ifndef butTarget1_h
#define butTarget1_h

#include "button.h"
#include "game.h"

class pButTarget1 : public pButton{
	pGame &game;
	public:
		pButTarget1(pGame &_game) : game(_game), pButton(39, 5, HIGH){};
		void onActive();
		
};

#endif
