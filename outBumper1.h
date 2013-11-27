#ifndef outBumper1_h
#define outBumper1_h

#include "outputs.h"

class pOutButton1 : public pOutputs{
	public:
		pOutButton1() : pOutputs(48, 70, 0, LOW){};
};

#endif