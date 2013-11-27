#ifndef outBumper2_h
#define outBumper2_h

#include "outputs.h"

class pOutBumper2 : public pOutputs{
	public:
		pOutBumper2() : pOutputs(50, 70, 0, LOW){};
};

#endif