#include "butBallReturned.h"

void pButBallReturned::onActive(){
	game.ballCount--;
	Serial.print(game.ballCount);
	Serial.write(" balls left\n");
	
}
