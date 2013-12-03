#include "buttons.h"

void pButBallReturned::onActive(){
	game.ballCount--;
	Serial.print(game.ballCount);
	Serial.write(" balls left\n");
	if (game.ballCount < 0){
		game.ballCount = 5;
		game.outputs[outReturnBall]->activate();
		game.outputs[outDropTargets]->activate();
	}
	
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
		game.lights[litTarget1]->lightOn();
		game.lights[litTarget2]->lightOn();
		game.lights[litTarget3]->lightOn();
	}
}

void pButLowBumperRight::onActive(){
	game.outputs[outLowBumperRight]->activate();
}

void pButLowBumperLeft::onActive(){
	game.outputs[outLowBumperLeft]->activate();
}

void pButReturnBall::onActive(){
	if (game.ballCount > 0){
		game.outputs[outReturnBall]->activate();
		game.outputs[outDropTargets]->activate();
	}
	
	if (game.ballCount <= 0){
		game.ballCount = 0;
		game.resetLoop();
	}
}

void pButTarget1::onActive(){
	Serial.write("Target 1 click\n");
	game.targetNum[0] = true;
	game.lights[litTarget1]->lightOff();
}

void pButTarget2::onActive(){
	Serial.write("Target 2 click\n");
	if (game.targetNum[0] == true){
		game.targetNum[1] = true;
		game.lights[litTarget2]->lightOff();
	}
}

void pButTarget3::onActive(){
	Serial.write("Target 3 click\n");
	if (game.targetNum[1] == true && game.targetNum[2] == false){
		game.targetNum[2] = true;
		game.outputs[outDropTargets]->activate();
		game.dropTargetAbility = false;
		game.lights[litTarget3]->lightOff();
		
	}
}

