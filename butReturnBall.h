#ifndef butReturnBall_h
#define butReturnBall_h

#include "button.h"
#include "game.h"

class pButReturnBall : public pButton{
	pGame &game;
	public:
		pButReturnBall(pGame &_game) : game(_game), pButton(47, 70, HIGH){};
		void onActive();
		
};

#endif
