#ifndef outputs_h
#define outputs_h

#include "output.h"
#include "game.h"

class pOutBumper1 : public pOutput{
	pGame &game;
	public:
		pOutBumper1(pGame &g) : game(g), pOutput(47, 70, 0, LOW){};
};

class pOutBumper2 : public pOutput{
	pGame &game;
	public:
		pOutBumper2(pGame &g) : game(g), pOutput(49, 70, 0, LOW){};
};

class pOutBumper3 : public pOutput{
	pGame &game;
	public:
		pOutBumper3(pGame &g) : game(g), pOutput(45, 70, 0, LOW){};
};

class pOutDropTargets : public pOutput{
	public:
		pGame &game;
		pOutDropTargets(pGame &g) : game(g), pOutput(53, 70, 500, LOW){};
		void onActive();
};

class pOutFlickUp : public pOutput{
	pGame &game;
	public:
		pOutFlickUp(pGame &g) : game(g), pOutput(39, 70, 1000, LOW){};
};

class pOutLowBumperLeft : public pOutput{
	pGame &game;
	public:
		pOutLowBumperLeft(pGame &g) : game(g), pOutput(51, 70, 0, LOW){};
};

class pOutLowBumperRight : public pOutput{
	pGame &game;
	public:
		pOutLowBumperRight(pGame &g) : game(g), pOutput(41, 70, 0, LOW){};
};

class pOutReturnBall : public pOutput{
	pGame &game;
	public:
		pOutReturnBall(pGame &g) : game(g), pOutput(43, 70, 1000, LOW){};
};



#endif