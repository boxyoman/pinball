#ifndef outBumper1_h
#define outBumper1_h

#include "outputs.h"

class pOutBumper1 : public pOutputs{
	public:
		pOutBumper1() : pOutputs(48, 70, 0, LOW){};
};

#endif