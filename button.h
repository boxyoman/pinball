#ifndef button_h
#define button_h

#include "Arduino.h"

enum{
	butBumper1,
	butBumper2,
	butBumper3,
	butDropTargets, 
	//butTargget2,
	//butTargget3,
	butFlickup,
	butReturnBall,
	butBallReturned,
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
	int onTime;				//debounce time
	public:
		pButton(){};
		pButton(int pin, int time, bool activeState);
		void loop();
		//for subclassing
		virtual void onActive(){};

};

#endif
