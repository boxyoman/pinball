#ifndef outDropTargets_h
#define outDropTargets_h

#include "outputs.h"

class pOutDropTargets : public pOutputs{
	public:
		pOutDropTargets() : pOutputs(44, 70, 500, LOW){};
};

#endif