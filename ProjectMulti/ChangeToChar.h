#pragma once
#include "Algo.h"
class ChangeToChar :
	public Algo
{
public:
	string encode(string encodedmessage);
	string decode(string encodedmessage);
	ChangeToChar();
	~ChangeToChar();
};

