#ifndef _LZW_H
#define _LZW_H
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
#endif

