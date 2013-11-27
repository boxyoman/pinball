#ifndef outBumper2_h
#define outBumper2_h

#include "outputs.h"

class pOutButton2 : public pOutputs{
	public:
		pOutButton2() : pOutputs(50, 70, 0, LOW){};
};

#endif