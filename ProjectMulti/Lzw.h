#pragma once
#include "Algo.h"
using namespace std;

class Lzw :
	public Algo
{
public:
	Lzw();
	string encode(string uncompressed);
	string decode(string compressed);
	~Lzw();
};

