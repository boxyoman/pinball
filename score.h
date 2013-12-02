#ifndef score_h
#define score_h

#include "game.h"

class pScore{
	int score;
	pGame &game;
public:
	//pScore(pGame &g): game(&g){};
	void reset();
	void add(int points);
	void operator +=(int points);
	void loop();
};


#endif
