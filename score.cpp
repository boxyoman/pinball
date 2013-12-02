#include "score.h"

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
	
}