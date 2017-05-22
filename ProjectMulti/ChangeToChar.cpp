#include "ChangeToChar.h"
#include<bitset>

string ChangeToChar::encode(string encodedmessage)
{
	split_message(encodedmessage);
	int r;
	if (m_message.size()>0)
		r = m_message.size() % 8;
	string charmessage = "";
	for (int i = 0; i < m_message.size(); )
	{

		if (i + 7 < m_message.size())
		{


			string temp = m_message.substr(i, 8);
			int count = 128, sum = 0;
			for (int k = 0; k < temp.size(); k++)
			{
				sum += (temp[k] - '0')*count;
				count /= 2;
			}
			//bitset<8>bits(temp);

			//unsigned char c = bits.to_ulong();
			charmessage += (char)sum;
			i += 8;
		}
		else if (i < m_message.size())
		{
			int ba2y = m_message.size() - i;
			string temp = "";
			int cur = 8 - ba2y;
			for (int j = 0; j < cur; ++j)temp += "0";
			temp=temp + m_message.substr(i, m_message.size() - i + 1);
			//unsigned char c = bits.to_ulong();
			int count = 128, sum = 0;
			for (int k = 0; k < temp.size(); k++)
			{
				sum += (temp[k] - '0')*count;
				count /= 2;
			}
			charmessage += (char)sum;
			break;
		}

	}
	charmessage = to_string(r) + charmessage;
	charmessage = m_prefix + charmessage;
	return charmessage;
}

string ChangeToChar::decode(string encodedmessage)
{
	split_message(encodedmessage);
	char temp;
	string bin;
	string result = "";
	int x = m_message[0] - '0';
	if (x != 0)
	{
		for (int i = 1; i < m_message.size() - 1; ++i)
		{
			temp = m_message[i];
			bin = "";
			for (int j = 7; j >= 0; --j)
			{
				bin += ((temp&(1 << j)) ? '1' : '0');
			}
			result += bin;

		}

		bin = "";
		temp = m_message[m_message.size() - 1];


		for (int j = x - 1; j >= 0; --j)
		{
			bin += ((temp&(1 << j)) ? '1' : '0');
		}
		result += bin;
	}
	else
	{
		for (int i = 1; i < m_message.size() ; ++i)
		{
			temp = m_message[i];
			bin = "";
			for (int j = 7; j >= 0; --j)
			{
				bin += ((temp&(1 << j)) ? '1' : '0');
			}
			result += bin;

		}
	}
	result = m_prefix + result;
	return result;
}

ChangeToChar::ChangeToChar()
{
}


ChangeToChar::~ChangeToChar()
{
}
