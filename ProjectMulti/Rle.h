#pragma once
#include "Algo.h"
class Rle :
	public Algo
{
public:
	Rle();
	virtual string encode(string message);

	virtual string decode(string encoded_message);
	~Rle();
};

