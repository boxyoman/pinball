#ifndef game_h
#define game_h

#include "output.h"
#include "button.h"

class pGame{
	public:
		int ballCount;
		bool targetNum[3];
		bool dropTargetsDown;
		bool dropTargetAbility;
		
		void loop();
		void setup();
		pOutput *outputs[numOfOutputs];
		pButton *buttons[numOfButtons];
};

#endif