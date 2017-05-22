#ifndef _ALGO_H
#define _ALGO_H
#include <string>
#include <fstream>

using namespace std;
class Algo
{
public:
	int m_width, m_length;
	string m_message, m_prefix;
	void split_message(string message);
	virtual string encode(string message) = 0;
	virtual string decode(string encoded_message) = 0;
	Algo();
	~Algo();
};
#endif

