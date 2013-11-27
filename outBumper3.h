#ifndef outBumper3_h
#define outBumper3_h

#include "outputs.h"

class pOutButton3 : public pOutputs{
	public:
		pOutButton3() : pOutputs(46, 70, 0, LOW){};
};

#endif