#include "game.h"

pGame game;

void setup(){
	Serial.begin(9600);
	Serial.write("Started\n");
	game.setup();
}

void loop(){
	game.loop();
}