#include "Rle.h"



Rle::Rle()
{
}

string Rle::encode(string message)
{
	int start_index=2;
	string result = message.substr(0, start_index);
	int width = (int)message[0] * 256 + (int)message[1];
	char B = 'B', W = 'W';
	char c = message[start_index];
	start_index++;
	int count = 1;
	for (int i = start_index; i < width-1; i++)
	{
		if (c==message[i+1])
		{
			count++;
		}
		else
		{
			result+= to_string(count);
			result += (c == '1') ? W : B;
			count = 1;
			c = message[i + 1];
		}
	}
	result += to_string(count);
	result += (c == '1') ? W : B;
	return result;
}


Rle::~Rle()
{
}
