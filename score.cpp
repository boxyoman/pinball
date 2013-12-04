#include "score.h"

void pScore::init(){
	scoreWheel[0] = new pButton(1, 70, 70, LOW);	//1
	scoreWheel[1] = new pButton(1, 70, 70, LOW);	//10
	scoreWheel[2] = new pButton(1, 70, 70, LOW);	//100
	scoreWheel[3] = new pButton(1, 70, 70, LOW);	//1000
	score = 0;
	displayedScore = 0;
	state = pScoreReset;
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
			if(scoreWheel[0]->state == swOff){
				//insert code to move score wheels
			}
	 		break;
		case pScoreNormal:
			if(displayedScore != score){
				int diff = score - displayedScore;
				if(scoreWheel[0]->state == swOff){
					if(diff%10 != 0){
						scoreWheel[0]->activate();
						displayedScore += 1;
					}
				}
				if(scoreWheel[1]->state == swOff){
					if(diff%100 != 0 && diff%100 > 10){
						scoreWheel[1]->activate();
						displayedScore += 10;
					}
				}
				if(scoreWheel[2]->state == swOff){
					if(diff%1000 != 0 && diff%1000 > 100){
						scoreWheel[2]->activate();
						displayedScore += 100;
					}
				}
				if(scoreWheel[3]->state == swOff){
					if(diff%10000 != 0 && diff%10000 > 1000){
						scoreWheel->activate();
						displayedScore += 1000;
					}
				}
			}
			break;
	}
}
