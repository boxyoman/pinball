#include "buttons.h"

void pButBallReturned::onActive(){
	game.ballCount--;
	Serial.print(game.ballCount);
	Serial.write(" balls left\n");
	
}

void pButBumper1::onActive(){
	game.outputs[outBumper1]->activate();
}

void pButBumper2::onActive(){
	game.outputs[outBumper2]->activate();
}

void pButBumper3::onActive(){
	game.outputs[outBumper3]->activate();
}

void pButDropTargets::onActive(){
	Serial.write("drop targets down\n");
	game.dropTargetsDown = true;
	if (game.dropTargetAbility){
		game.outputs[outDropTargets]->activate();
	}
}

void pButFlickup::onActive(){
	game.outputs[outFlickUp]->activate();
	if (game.targetNum[0] && game.targetNum[1] && game.targetNum[0] && game.targetNum[2] && game.dropTargetsDown){
		game.outputs[outDropTargets]->activate();
		game.dropTargetAbility = true;
		game.targetNum[0] = false;
		game.targetNum[1] = false;
		game.targetNum[2] = false;
	}
}

void pButLowBumperRight::onActive(){
	game.outputs[outLowBumperRight]->activate();
}

void pButLowBumperLeft::onActive(){
	game.outputs[outLowBumperLeft]->activate();
}

void pButReturnBall::onActive(){
	Serial.write("pButReturnBall onActive\n");
	
	if (game.ballCount > 0){
		game.outputs[outReturnBall]->activate();
		game.outputs[outDropTargets]->activate();
	}
	
}

void pButTarget1::onActive(){
	Serial.write("Target 1 click\n");
	game.targetNum[0] = true;
}

void pButTarget2::onActive(){
	Serial.write("Target 2 click\n");
	if (game.targetNum[0] == true){
		game.targetNum[1] = true;
	}
}

void pButTarget3::onActive(){
	Serial.write("Target 3 click\n");
	if (game.targetNum[1] == true && game.targetNum[2] == false){
		game.targetNum[2] = true;
		game.outputs[outDropTargets]->activate();
		game.dropTargetAbility = false;
		
	}
}

