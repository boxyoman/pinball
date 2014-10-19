#ifndef outputs_h
#define outputs_h

#include "output.h"
#include "game.h"

class pOutBumper1 : public pOutput{
	pGame &game;
	public:
		pOutBumper1(pGame &g) : pOutput(47, 70, 0, LOW), game(g){};
		void onActive();
};

class pOutBumper2 : public pOutput{
	pGame &game;
	public:
		pOutBumper2(pGame &g) : pOutput(49, 70, 0, LOW), game(g){};
		void onActive();
};

class pOutBumper3 : public pOutput{
	pGame &game;
	public:
		pOutBumper3(pGame &g) : pOutput(45, 70, 0, LOW), game(g){};
		void onActive();
};

class pOutDropTargets : public pOutput{
	public:
		pGame &game;
		pOutDropTargets(pGame &g) : pOutput(53, 70, 500, LOW), game(g){};
		void onActive();
};

class pOutFlickUp : public pOutput{
	pGame &game;
	public:
		pOutFlickUp(pGame &g) : pOutput(39, 70, 1000, LOW), game(g){};
};

class pOutLowBumperLeft : public pOutput{
	pGame &game;
	public:
		pOutLowBumperLeft(pGame &g) : pOutput(51, 70, 0, LOW), game(g){};
};

class pOutLowBumperRight : public pOutput{
	pGame &game;
	public:
		pOutLowBumperRight(pGame &g) : pOutput(41, 70, 0, LOW), game(g){};
};

class pOutReturnBall : public pOutput{
	pGame &game;
	public:
		pOutReturnBall(pGame &g) : pOutput(43, 70, 1000, LOW), game(g){};
};



#endif
