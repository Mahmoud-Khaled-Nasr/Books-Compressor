#include "RangeAlgo.h"
#include<vector>
#include<string>

RangeAlgo::RangeAlgo()
{
}


RangeAlgo::~RangeAlgo()
{
}

string RangeAlgo::encode(string message)
{
	string result = "";
	split_message(message);
	
	vector<int>spaces;
	spaces.push_back(-1);

	vector<int>encodedintegers;
	vector<int>tempencodedintegers;
	for (int i = 0; i < m_message.size(); ++i)
	{
		if (m_message[i] == ' ')spaces.push_back(i);
	}
	spaces.push_back(m_message.size());
	for (int i = 1; i < spaces.size(); ++i)
	{
		string temp = "";
		for (int j = spaces[i - 1] + 1; j < spaces[i]; ++j)temp += m_message[j];
		encodedintegers.push_back(stoi(temp));
	}
	tempencodedintegers = encodedintegers;
	for (int i = 1; i < encodedintegers.size(); ++i)
	{
		tempencodedintegers[i] = encodedintegers[i] - encodedintegers[i - 1];
	}
	for (int i = 0; i < tempencodedintegers.size(); ++i)
	{
		result += to_string(tempencodedintegers[i]);
		if (i != tempencodedintegers.size() - 1)result += " ";
	}
	result = m_prefix + result;
	return result;
}

string RangeAlgo::decode(string message)
{
	split_message(message);
	string result = "";
	vector<int>spaces;
	vector<int>decodedintegers;
	vector<int>tempdecodedintegers;
	spaces.push_back(-1);
	for (int i = 0; i < m_message.size(); ++i)
	{
		if (m_message[i] == ' ')spaces.push_back(i);
	}
	spaces.push_back(m_message.size());
	for (int i = 1; i < spaces.size(); ++i)
	{
		string temp = "";
		for (int j = spaces[i - 1] + 1; j < spaces[i]; ++j)temp += m_message[j];
		decodedintegers.push_back(stoi(temp));
	}
	tempdecodedintegers = decodedintegers;
	for (int i = 1; i < decodedintegers.size(); ++i)
	{
		tempdecodedintegers[i] = decodedintegers[i] + tempdecodedintegers[i - 1];
	}
	for (int i = 0; i < tempdecodedintegers.size(); ++i)
	{
		result += to_string(tempdecodedintegers[i]);
		if (i != tempdecodedintegers.size() - 1)result += " ";
	}
	result = m_prefix + result;
	return result;
}
