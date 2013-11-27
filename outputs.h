#ifndef outputs_h
#define outputs_h

#include "Arduino.h"

enum {
	outBumper1,
	outBumper2,
	outBumper3,
	outDropTargets,
	outFlickUp,
	//outReturnBall,
	numOfOutputs
};

typedef enum{
	swInDelay,
	swOn,
	swOff,
} switchStates;

class pOutputs{
	public:
		pOutputs();
		pOutputs(int pinNum, int onTime, int delayTime);
		pOutputs(int pinNum, int onTime, int delayTime, bool activeState);
		int pinNum;
		int onTime; //the amount of time the switch should be on for(in milliseconds)
		int delayTime;
		bool state;
		bool activeState;
		switchStates switchState;
		void loop(); //call every tick
		void activate();
	
	protected:
		//for subclassing
		virtual void onActive(){};
		virtual void onDeavtive(){};
	
	
	private:
		unsigned long startTime;
		void setup();
};

#endif
