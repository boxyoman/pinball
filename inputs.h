#ifndef input_h
#define input_h

#include <Button.h>
#include "trigger.h"

class input{
public:
	Button button;
	int pinNum;
	int activeState;
	int state;
	
	void check();
	virtual void trigger();
	
	input(int pinNum);
	input(int pinNum, int activeState);
	~input();
};


#endif