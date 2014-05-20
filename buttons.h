#ifndef buttons_h
#define buttons_h

#include "button.h"
#include "game.h"

class pButBallReturned : public pButton{
	pGame &game;
	public:
		pButBallReturned(pGame &_game) : game(_game), pButton(46, 70, HIGH){};
		void onActive();
};

class pButReturnBall : public pButton{
	pGame &game;
	public:
		pButReturnBall(pGame &_game) : game(_game), pButton(44, 70, HIGH){};
		void onActive();
};

class pButStart : public pButton{
	pGame &game;
	public:
		pButStart(pGame &_game) : game(_game), pButton(50, 70, HIGH){};
		void onActive();
};

class pButBumper1 : public pButton{
	pGame &game;
	public:
		pButBumper1(pGame &_game) : game(_game), pButton(22, 1, HIGH){};
		void onActive();
};

class pButBumper2 : public pButton{
	pGame &game;
	
	public:
		pButBumper2(pGame &_game) : game(_game), pButton(24, 1, HIGH){};
		void onActive();
};

class pButBumper3 : public pButton{
	pGame &game;
	
	public:
		pButBumper3(pGame &_game) : game(_game), pButton(26, 1, HIGH){};
		void onActive();
};

class pButDropTargets : public pButton{
	pGame &game;
	
	public:
		pButDropTargets(pGame &_game) : game(_game), pButton(40, 200, HIGH){};
		void onActive();
};

class pButFlickup : public pButton{
	pGame &game;
	
	public:
		pButFlickup(pGame &_game) : game(_game), pButton(38, 70, HIGH){};
		void onActive();
};

class pButLowBumperRight : public pButton{
	pGame &game;
	
	public:
		pButLowBumperRight(pGame &_game) : game(_game), pButton(36, 1, HIGH){};
		void onActive();
};

class pButLowBumperLeft : public pButton{
	pGame &game;
	
	public:
		pButLowBumperLeft(pGame &_game) : game(_game), pButton(34, 1, HIGH){};
		void onActive();
};

class pButTarget1 : public pButton{
	pGame &game;
	public:
		pButTarget1(pGame &_game) : game(_game), pButton(28, 5, HIGH){};
		void onActive();
};

class pButTarget2 : public pButton{
	pGame &game;
	public:
		pButTarget2(pGame &_game) : game(_game), pButton(30, 5, HIGH){};
		void onActive();
};

class pButTarget3 : public pButton{
	pGame &game;
	public:
		pButTarget3(pGame &_game) : game(_game), pButton(32, 5, HIGH){};
		void onActive();
};

#endif
