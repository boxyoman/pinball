#ifndef outBallReturn_h
#define outBallReturn_h

#include "outputs.h"

class pOutBallReturn : public pOutputs{
	public:
		pOutBallReturn() : pOutputs(42, 70, 1000, LOW){};
};

#endif