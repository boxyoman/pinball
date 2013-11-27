#ifndef butFlickup_h
#define butFlickup_h

#include "button.h"
#include "game.h"


class pOutFlickup : public pButton{
	public:
		pGame game;
		pOutFlickup(pGame &game) : pButton(53, 70, HIGH){};
		void onActive();
};

#endif