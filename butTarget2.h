#ifndef butTarget2_h
#define butTarget2_h

#include "button.h"
#include "game.h"

class pButTarget2 : public pButton{
	pGame &game;
	public:
		pButTarget2(pGame &_game) : game(_game), pButton(37, 5, HIGH){};
		void onActive();
		
};

#endif
