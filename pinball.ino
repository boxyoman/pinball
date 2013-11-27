#include <Button.h>
#include "switch.h"


typedef enum{
	stGameBegin,
	stReturnBall,
	stBallinPlay,
	stGameOver,
} gameStates;

gameStates gameSt;
void loopSwitches();
/*
        .--.
       |o_o |
       |:_/ |
      //   \ \
     (|     | )
    /'\_   _/`\
    \___)=(___/
*/
//I think we are going to try to avoid using delay(); as much as possible

pSwitch outputs[numOfSwitches];
Button button[7] = {
	Button(53,PULLDOWN),
	Button(51,PULLDOWN), 
	Button(49,PULLDOWN), 
	Button(47,PULLDOWN), 
	Button(45,PULLDOWN), 
	Button(43,PULLDOWN), 	//senses ball returned
	Button(41,PULLDOWN)		//senses ball return ready
};

void setupSwitches(){
	outputs[flickUp] = pSwitch(52, 70, 1000, LOW);
	outputs[bumper2] = pSwitch(50, 70, 0, LOW);
	outputs[bumper1] = pSwitch(48, 70, 0, LOW);
	outputs[bumper3] = pSwitch(46, 70, 0, LOW);
	outputs[dropTarggets] = pSwitch(44, 70, 500, LOW);
	outputs[swReturnBall] = pSwitch(42, 70, 1000, LOW);
}

void setup(){
	Serial.begin(9600);
	Serial.write("Started\n");
	setupSwitches();
	
	gameSt = stBallinPlay;
}

void ballPlay(){
	if(button[0].uniquePress()){
		outputs[flickUp].activate();
	}
	//set off bumper 2
	if(button[1].uniquePress()){
		if(outputs[bumper1].switchState == swOff && outputs[bumper3].switchState == swOff){
			outputs[bumper2].activate();
		}
	}
	//set off bumper 3
	if(button[2].uniquePress()){
		if(outputs[bumper2].switchState == swOff && outputs[bumper1].switchState == swOff){
			outputs[bumper3].activate();
		}
	}

	//set off bumper 1
	if(button[3].uniquePress()){
		if(outputs[bumper2].switchState == swOff && outputs[bumper3].switchState == swOff){
			outputs[bumper1].activate();
		}
	}
	//drop tarrgets
	if(button[4].uniquePress()){
		outputs[dropTarggets].activate();
	}
	
	if(button[6].uniquePress()){
		gameSt = stReturnBall;
	}
}

void loopSwitches(){
	outputs[flickUp].loop();
	outputs[bumper1].loop();
	outputs[bumper2].loop();
	outputs[bumper3].loop();
	outputs[dropTarggets].loop();
	outputs[swReturnBall].loop();
}
int state = 0;
void returnBall(){
	if(state == 0){
		outputs[dropTarggets].activate();
		outputs[swReturnBall].activate();
		state = 1;
	}else if(state == 1 && outputs[swReturnBall].switchState == swOff){
		if(button[5].uniquePress()){
			gameSt = stBallinPlay;
			state = 0;
		}else if(button[6].uniquePress()){
			state = 0;
		}
	}
}

void loop(){
	switch (gameSt){
		case stBallinPlay:
			ballPlay();
			break;
		case stReturnBall:
			returnBall();
			break;
	}
	loopSwitches();
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
