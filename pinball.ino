#include <Button.h>
#include "switch.h"

//I think we are going to try to avoid using delay(); as much as possible

pSwitch switches[numOfSwitches];
Button button[4] = {Button(53,PULLDOWN), Button(51,PULLDOWN), Button(49,PULLDOWN), Button(47,PULLDOWN)};

void setupSwitches(){
	switches[flickUp] = pSwitch(52, 70, 1000, LOW);
	switches[bumper2] = pSwitch(50, 70, 0, LOW);
	switches[bumper1] = pSwitch(48, 70, 0, LOW);
	switches[bumper3] = pSwitch(46, 70, 0, LOW);
}

void setup(){
	Serial.begin(9600);
	Serial.write("Started\n");
	setupSwitches();
}

void loop(){
	if(button[0].uniquePress()){
		switches[flickUp].activate();
	}
	//set off bumper 2
	if(button[1].uniquePress()){
		switches[bumper2].activate();
	}
	//set off bumper 3
	if(button[2].uniquePress()){
		switches[bumper3].activate();
	}
	//set off bumper 1
	if(button[3].uniquePress()){
		switches[bumper1].activate();
	}
	
	switches[flickUp].loop();
	switches[bumper1].loop();
	switches[bumper2].loop();
	switches[bumper3].loop();
}

/*
void returnBall(){
  if(ballStatus == 1){
    ballNumber++;
    ballStatus = 0;
  }
  if(ballNumber > 5 ){
    start = 1;
  }else{
    delay(300);
    ballReturnButton.listen();
    changeState(&ballReturnRelay, LOW);
    ballReturnButton.listen();
    delay(50);
    ballReturnButton.listen();
    changeState(&ballReturnRelay, HIGH);
  }
}
*/
