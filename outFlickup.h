#ifndef outFlickup_h
#define outFlickup_h

#include "outputs.h"

class pOutFlickUp : public pOutputs{
	public:
		pOutFlickUp() : pOutputs(52, 70, 1000, LOW){};
};

#endif