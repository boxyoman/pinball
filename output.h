#ifndef output_h
#define output_h

#include "Arduino.h"

enum {
	outBumper1,
	outBumper2,
	outBumper3,
	outDropTargets,
	outFlickUp,
	outReturnBall,
	outLowBumperRight,
	outLowBumperLeft,
	numOfOutputs
};

typedef enum{
	swInDelay=0,
	swOn=1,
	swOff=3,
} switchStates;

class pOutput{
	public:
		pOutput();
		pOutput(int pinNum, int onTime, int delayTime);
		pOutput(int pinNum, int onTime, int delayTime, bool activeState);
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
