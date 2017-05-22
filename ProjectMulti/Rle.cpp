#include "Rle.h"



Rle::Rle()
{
}

string Rle::encode(string message)
{
	int sum = 0;
	split_message(message);
	string result = m_prefix;// message.substr(0, start_index);
	char B = 'B', W = 'W';
	char c = m_message[0];
	int count = 1;
	for (int i = 0; i < m_message.size()-1 && m_message[i+1]!='\n'; i++)
	{
		if (c== m_message[i+1])
		{
			count++;
		}
		else
		{
			sum += count;
			result+= to_string(count);
			result += (c == '1') ? W : B;
			count = 1;
			c = m_message[i + 1];
		}
	}
	sum += count;
	result += to_string(count);
	result += (c == '1') ? W : B;
	//cout << "the total number of chars is " << sum;
	return result;
}


string Rle::decode(string encoded_message)
{
	split_message(encoded_message);
	string result = m_prefix;
	char B = 'B', W = 'W';
	int lst = 0;
	for (int i = 0; i < m_message.size() && m_message[i]!='\n'; i++)
	{
		if (m_message[i] == W)
		{
			for (int j = 0; j < stoi(m_message.substr(lst, i - lst)); j++)
				result+='1';

			lst = i + 1;
		}
		else if (m_message[i] == B)
		{
			for (int j = 0; j < stoi(m_message.substr(lst, i - lst)); j++)
				result += '0';
			lst = i + 1;
		}
	}
	return result;
}

Rle::~Rle()
{
}
