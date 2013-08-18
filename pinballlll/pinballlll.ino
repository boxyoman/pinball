#include <Button.h>

enum relayNum{
  scorePin = 31,
  ballReturnPin = 33
  
};

typedef struct Relay
{
  relayNum pin;
  int state;
}Relay;

void changeState(Relay *re, int state);

Relay scoreResetRelay = {scorePin, HIGH};
Relay ballReturnRelay = {ballReturnPin, HIGH};

Button startButton = Button(30, HIGH);
Button ballReturnButton = Button(32, HIGH);
Button ballReturnCheckSwitch = Button(34, HIGH);

void changeState(Relay *re, int state){
  re->state = state;
  digitalWrite(re->pin, re->state);
}


int ballStatus = 0;
int start = 1;
int i;
int ballNumber = 1;

void setup()
{
 /* pinMode(startButton, INPUT);
  pinMode(ballReturnButton, INPUT);
  pinMode(ballReturnCheckSwitch, INPUT); */
  pinMode(scoreResetRelay.pin, OUTPUT);
  pinMode(ballReturnRelay.pin, OUTPUT);
  
  digitalWrite(scoreResetRelay.pin, scoreResetRelay.state);
  digitalWrite(ballReturnRelay.pin, ballReturnRelay.state);
  
}


void loop()
{
  if(start==1){
    startButton.listen();
    
     if (startButton.onPress()){
       for(i = 0; i < 11; i++){
         startButton.listen();
         changeState(&scoreResetRelay, LOW);
         delay(100);
         changeState(&scoreResetRelay, HIGH);
         delay(100);
       }
       ballNumber = 1;
       ballStatus = 0;
       start = 0;
       returnBall();
     }
  }else{
    ballReturnButton.listen();
    ballReturnCheckSwitch.listen();
    if(ballReturnButton.onPress()){
      returnBall();
    }
    if(ballReturnCheckSwitch.onPress()){
      ballStatus = 1;
    }
    
  }
}


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
