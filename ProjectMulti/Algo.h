#pragma once
#include <string>
#include <fstream>

using namespace std;
class Algo
{
public:
	virtual string encode(string message) = 0;
	virtual string decode(string encoded_message) = 0;
	Algo();
	~Algo();
};

