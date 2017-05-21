#include "Rle.h"



Rle::Rle()
{
}

string Rle::encode(string message)
{
	int start_index=5;
	string result = message.substr(0, start_index);
	int width = (int)message[0] * 256 + (int)message[1];
	char B = 'B', W = 'W';
	char c = message[start_index];
	start_index++;
	int count = 1;
	for (int i = start_index; i < message.size()-1 && message[i+1]!='\n'; i++)
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


string Rle::decode(string encoded_message)
{
	int start_index = 5;
	string result = encoded_message.substr(0, start_index);
	int width = (int)encoded_message[0] * 256 + (int)encoded_message[1];
	char B = 'B', W = 'W';
	int lst = start_index;
	for (int i = 0; i < encoded_message.size(); i++)
	{
		if (encoded_message[i] == W)
		{
			for (int j = 0; j < stoi(encoded_message.substr(lst, i - lst)); j++)
				result+='1';
			lst = i + 1;
		}
		else if (encoded_message[i] == B)
		{
			for (int j = 0; j < stoi(encoded_message.substr(lst, i - lst)); j++)
				result += '0';
			lst = i + 1;
		}
	}
	return result;
}

Rle::~Rle()
{
}
