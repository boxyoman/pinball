#include "butTarget2.h"

void pButTarget2::onActive(){
	Serial.write("Target 2 click\n");
	if (game.targetNum[0] == true){
		game.targetNum[1] = true;
	}
}
