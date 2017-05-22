#pragma once
#include "Algo.h"
class RangeAlgo :
	public Algo
{
public:
	RangeAlgo();
	~RangeAlgo();
	virtual string encode(string message);
	virtual string decode(string encoded);
};

