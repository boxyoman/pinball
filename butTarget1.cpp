#include "butTarget1.h"

void pButTarget1::onActive(){
	Serial.write("Target 1 click\n");
	game.targetNum[0] = true;
}
