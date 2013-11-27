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

pSwitch switches[numOfSwitches];
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
	switches[flickUp] = pSwitch(52, 70, 1000, LOW);
	switches[bumper2] = pSwitch(50, 70, 0, LOW);
	switches[bumper1] = pSwitch(48, 70, 0, LOW);
	switches[bumper3] = pSwitch(46, 70, 0, LOW);
	switches[dropTarggets] = pSwitch(44, 70, 500, LOW);
	switches[swReturnBall] = pSwitch(42, 70, 1000, LOW);
}

void setup(){
	Serial.begin(9600);
	Serial.write("Started\n");
	setupSwitches();
	
	gameSt = stBallinPlay;
}

void ballPlay(){
	if(button[0].uniquePress()){
		switches[flickUp].activate();
	}
	//set off bumper 2
	if(button[1].uniquePress()){
		if(switches[bumper1].switchState == swOff && switches[bumper3].switchState == swOff){
			switches[bumper2].activate();
		}
	}
	//set off bumper 3
	if(button[2].uniquePress()){
		if(switches[bumper2].switchState == swOff && switches[bumper1].switchState == swOff){
			switches[bumper3].activate();
		}
	}

	//set off bumper 1
	if(button[3].uniquePress()){
		if(switches[bumper2].switchState == swOff && switches[bumper3].switchState == swOff){
			switches[bumper1].activate();
		}
	}
	//drop tarrgets
	if(button[4].uniquePress()){
		switches[dropTarggets].activate();
	}
	
	if(button[6].uniquePress()){
		gameSt = stReturnBall;
	}
	
	loopSwitches();
}

void loopSwitches(){
	switches[flickUp].loop();
	switches[bumper1].loop();
	switches[bumper2].loop();
	switches[bumper3].loop();
	switches[dropTarggets].loop();
	switches[swReturnBall].loop();
}
int state = 0;
void returnBall(){
	loopSwitches();
	if(state == 0){
		switches[dropTarggets].activate();
		switches[swReturnBall].activate();
		state = 1;
	}else if(state == 1 && switches[swReturnBall].switchState == swOff){
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
