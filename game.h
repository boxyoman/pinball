#ifndef game_h
#define game_h

#include "output.h"
#include "button.h"
#include "light.h"

class pGame{
	public:
		int ballCount;
		bool targetNum[3];
		bool dropTargetsDown;
		bool dropTargetAbility;
		
		void loop();
		void setup();
		void resetLoop();
		void reset();
		pOutput *outputs[numOfOutputs];
		pButton *buttons[numOfButtons];
		pLight *lights[numOfLights];
};

#endif