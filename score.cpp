#include "score.h"
#include "game.h"

void pScore::init(){
	scoreWheels[0] = new pOutput(25, 70, 70, LOW);	//1
	scoreWheels[1] = new pOutput(27, 70, 70, LOW);	//10
	scoreWheels[2] = new pOutput(29, 70, 70, LOW);	//100
	scoreWheels[3] = new pOutput(31, 70, 70, LOW);	//1000
	resetOut = new pOutput(23, 70, 70, LOW);
	score = 0;
	displayedScore = 0;
	state = pScoreNormal;
}

void pScore::reset(){
	score = 0;
	for(int i=0; i<10; i++){
		resetOut->activate();
		while(resetOut->switchState != swOff){
			resetOut->loop();
		}
	}
}

void pScore::add(int points){
	score += points;
}

void pScore::loop(){
	if(displayedScore != score){
		int diff = score - displayedScore;
		if(scoreWheels[0]->switchState == swOff && scoreWheels[1]->switchState == swOff && scoreWheels[2]->switchState == swOff && scoreWheels[3]->switchState == swOff){
			if(diff/1000 != 0){
				Serial.write("Add 1000\n");
				scoreWheels[3]->activate();
				displayedScore += 1000;
			}else if(diff/100 != 0){
				Serial.write("Add 100\n");
				scoreWheels[2]->activate();
				displayedScore += 100;
			}else if(diff/10 != 0){
				Serial.write("Add 10\n");
				scoreWheels[1]->activate();
				displayedScore += 10;
			}else if(diff != 0){
				Serial.write("Add 1\n");
				scoreWheels[0]->activate();
				displayedScore += 1;
			}
		}
	}
	for(int i=0; i<4; i++){
		scoreWheels[i]->loop();
	}
}
