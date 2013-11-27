#ifndef butReturnBall_h
#define butReturnBall_h

#include "button.h"
#include "game.h"

class pButReturnBall : public pButton{
	pGame &game;
	public:
		pButReturnBall(pGame &_game) : game(_game), pButton(41, 70, HIGH){ Serial.write("pButReturnBall initialized\n"); };
		void onActive();
		
};

#endif
