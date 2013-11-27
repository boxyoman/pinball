#ifndef outBallReturn_h
#define outBallReturn_h

#include "outputs.h"

class pOutReturnBall : public pOutputs{
	public:
		pOutReturnBall() : pOutputs(42, 70, 1000, LOW){};
};

#endif