#ifndef button_h
#define button_h

#include "Arduino.h"

enum{
	butBumper1,
	butBumper2,
	butBumper3,
	butDropTarggets,
	butTargget2,
	butTargget3,
	butFlickUp,
	butReturnBall,
	butBallReturned,
	numOfButtons;
};

class pButton{
	int pin;
	bool activeState;
	bool lastState;
	bool stateEqual;
	bool state;
	unsigned long startTime;
	int onTime;				//debounce time
	public:
		pButton(int pin, int time, bool activeState);
		void loop();
		
	protected:
		//for subclassing
		virtual void onActive(){};

};

#endif