#ifndef butTarget3_h
#define butTarget3_h

#include "button.h"
#include "game.h"

class pButTarget3 : public pButton{
	pGame &game;
	public:
		pButTarget3(pGame &_game) : game(_game), pButton(35, 20, HIGH){};
		void onActive();
		
};

#endif
