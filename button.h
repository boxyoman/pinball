#ifndef button_h
#define button_h

#include "Arduino.h"

enum{
	butBumper1,
	butBumper2,
	butBumper3,
	butDropTargets,
	butTarget1, 
	butTarget2,
	butTarget3,
	butFlickup,
	butReturnBall,
	butBallReturned,
	butLowBumperLeft,
	butLowBumperRight,
	butStart,
	numOfButtons
};

class pButton{
	int pin;
	bool letGo;
	bool activeState;
	bool lastState;
	bool stateEqual;
	bool state;
	unsigned long startTime;
	unsigned long onTime;				//debounce time
	public:
		pButton(){};
		pButton(int pin, int time, bool activeState);
		void loop();
		
	private:
		//for subclassing
		virtual void onActive(){};
		

};

#endif
