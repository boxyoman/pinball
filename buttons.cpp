#include "buttons.h"

void pButReturnBall::onActive(){
	if (game.ballCount > 0){
		game.outputs[outReturnBall]->activate();
		game.outputs[outDropTargets]->activate();
	}
	if (game.ballCount <= 0){
		game.resetLoop();
	}
}

void pButBallReturned::onActive(){
	game.ballCount--;
	Serial.print(game.ballCount);
	Serial.write(" balls left\n");
}

void pButStart::onActive(){
	Serial.write("Start Pressed!\n");
	if (game.ballCount <= 0){
		game.reset();
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
	game.score->add(200);
	game.dropTargetsDown = true;
	if (game.dropTargetAbility){
		game.outputs[outDropTargets]->activate();
	}
}

void pButFlickup::onActive(){
	game.score->add(100);
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
	game.score->add(10);
	game.outputs[outLowBumperRight]->activate();
}

void pButLowBumperLeft::onActive(){
	game.score->add(10);
	game.outputs[outLowBumperLeft]->activate();
}

void pButTarget1::onActive(){
	game.targetNum[0] = true;
	game.lights[litTarget1]->lightOff();
	game.score->add(25);
}

void pButTarget2::onActive(){
	game.score->add(25);
	if (game.targetNum[0] == true){
		game.targetNum[1] = true;
		game.lights[litTarget2]->lightOff();
	}
}

void pButTarget3::onActive(){
	game.score->add(25);
	if (game.targetNum[1] == true && game.targetNum[2] == false){
		game.targetNum[2] = true;
		game.outputs[outDropTargets]->activate();
		game.dropTargetAbility = false;
		game.lights[litTarget3]->lightOff();
		
	}
}

