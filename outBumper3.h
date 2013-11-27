#ifndef outBumper3_h
#define outBumper3_h

#include "outputs.h"

class pOutBumper3 : public pOutputs{
	public:
		pOutBumper3() : pOutputs(46, 70, 0, LOW){};
};

#endif