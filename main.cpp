#include "game.h"
pGame game;
void setup(){
	game.setup();
}
void loop(){
	game.loop();
}

int main(){
	init();
	setup();
	while(1){
		loop();
	}
}
