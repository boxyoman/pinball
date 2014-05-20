#include "score.h"

void pScore::init(){
	scoreWheels[0] = new pOutput(25, 70, 0, LOW);	//1
	scoreWheels[1] = new pOutput(27, 70, 0, LOW);	//10
	scoreWheels[2] = new pOutput(29, 70, 0, LOW);	//100
	scoreWheels[3] = new pOutput(31, 70, 0, LOW);	//1000
	score = 0;
	displayedScore = 0;
	state = pScoreNormal;
}

void pScore::reset(){
	score = 0;
}

void pScore::add(int points){
	score += points;
}

void pScore::operator +=(int points){
	this->add(points);
}

void pScore::loop(){
	switch (state){
		case pScoreReset:
			if(scoreWheels[0]->state == swOff){
				//insert code to move score wheels
			}
	 		break;
		case pScoreNormal:
			if(displayedScore != score){
				int diff = score - displayedScore;
				Serial.print(scoreWheels[1]->state);
				Serial.write("\n");
				if(scoreWheels[0]->state == swOff){
					if(diff%10 != 0){
						scoreWheels[0]->activate();
						displayedScore += 1;
					}
				}else if(scoreWheels[1]->state == swOff){
					if(diff%100 != 0 && diff%100 > 10){
						scoreWheels[1]->activate();
						displayedScore += 10;
					}
				}else if(scoreWheels[2]->state == swOff){
					if(diff%1000 != 0 && diff%1000 > 100){
						scoreWheels[2]->activate();
						displayedScore += 100;
					}
				}else if(scoreWheels[3]->state == swOff){
					if(diff%10000 != 0 && diff%10000 > 1000){
						scoreWheels[3]->activate();
						displayedScore += 1000;
					}
				}
			}
			break;
	}
	for(int i=0; i<4; i++){
		scoreWheels[i]->loop();
	}
}
