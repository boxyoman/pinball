#ifndef game_h
#define game_h

#include "outputs.h"

class pGame{
	public:
		void loop();
		void setup();
		pOutputs outputs[numOfOutputs];
		pButton buttons[numOfButtons];
};

#endif