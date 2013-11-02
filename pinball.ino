#include <Button.h>
#include "switch.h"

//I think we are going to try to avoid using delay(); as much as possible

pSwitch switches[2];
Button button = Button(53,PULLDOWN);

void setupSwitches(){
	switches[1] = pSwitch(52, 100, 1000, LOW);
}

void setup(){
	Serial.begin(9600);
	Serial.write("Started\n");
	setupSwitches();
}

void loop(){
	if(button.uniquePress()){
		switches[1].avtivate();
	}
	
	switches[1].loop();
	
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
