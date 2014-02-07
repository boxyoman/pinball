#ifndef score_h
#define score_h


#include "Arduino.h"
#include "output.h"

class pGame;

typedef enum{
	pScoreReset,
	pScoreNormal
}pScoreState;

class pScore{
	int score;
	int displayedScore;
	pGame &game;
	pOutput *scoreWheels[4];
public:
	pScoreState state;
	pScore(pGame &g): game(g){
		init();	
	};
	void init();
	void reset();
	void add(int points);
	void operator +=(int points);
	void loop();
};


#endif
