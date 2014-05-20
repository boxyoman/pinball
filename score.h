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
	int score;						//the current score
	int displayedScore;				//the current score on the score wheels
	pGame &game;
	pOutput *scoreWheels[4];
public:
	pScoreState state;
	pScore(pGame &g): game(g){
		init();	
	};
	void init();
	void reset();					//reset score
	void add(int points);			//add some more points
	void loop();
};


#endif
