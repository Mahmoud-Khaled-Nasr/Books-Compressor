#include "ChangeToChar.h"
#include<bitset>

string ChangeToChar::encode(string encodedmessage)
{
	int r;
	if (encodedmessage.size()>0)
		r = encodedmessage.size() % 8;
	string charmessage = "";
	for (int i = 0; i < encodedmessage.size(); )
	{

		if (i + 7 < encodedmessage.size())
		{


			string temp = encodedmessage.substr(i, 8);
			bitset<8>bits(temp);
			unsigned char c = bits.to_ulong();
			charmessage += c;
			i += 8;
		}
		else if (i < encodedmessage.size())
		{
			int ba2y = encodedmessage.size() - i;
			string temp = "";
			int cur = 8 - ba2y;
			for (int j = 0; j < cur; ++j)temp += "0";
			bitset<8>bits(temp + encodedmessage.substr(i, encodedmessage.size() - i + 1));
			unsigned char c = bits.to_ulong();
			charmessage += c;
			break;
		}

	}
	charmessage = to_string(r) + charmessage;
	return charmessage;
}

string ChangeToChar::decode(string encodedmessage)
{
	char temp;
	string bin;
	string result = "";
	for (int i = 1; i < encodedmessage.size() - 1; ++i)
	{
		temp = encodedmessage[i];
		bin = "";
		for (int j = 7; j >= 0; --j)
		{
			bin += ((temp&(1 << j)) ? '1' : '0');
		}
		result += bin;

	}
	int x = encodedmessage[0] - '0';
	bin = "";
	temp = encodedmessage[encodedmessage.size() - 1];
	for (int j = x - 1; j >= 0; --j)
	{
		bin += ((temp&(1 << j)) ? '1' : '0');
	}
	result += bin;
	return result;
}

ChangeToChar::ChangeToChar()
{
}


ChangeToChar::~ChangeToChar()
{
}
