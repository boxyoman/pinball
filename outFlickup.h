#ifndef outFlickup_h
#define outFlickup_h

#include "outputs.h"

class pOutFlickup : public pOutputs{
	protected:
		pOutFlickup() : pOutputs(52, 70, 1000, LOW){};
};

#endif flickup_h