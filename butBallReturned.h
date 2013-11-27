#ifndef butBallReturned_h
#define butBallReturned_h

#include "button.h"
#include "game.h"

class pButBallReturned : public pButton{
	pGame &game;
	public:
		pButBallReturned(pGame &_game) : game(_game), pButton(43, 70, HIGH){};
		void onActive();
		
};

#endif
