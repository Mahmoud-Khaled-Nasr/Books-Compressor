#include "Lzw.h"
#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<string>
#include<list>
#include<utility>
#include<algorithm>

using namespace std;


Lzw::Lzw()
{
}

string Lzw::encode(string uncompressed)
{
	ofstream ofile;
	map<string, int> dictionary;
	string s = "";
	for (int i = 0; i < 256; i++)
		dictionary.insert(make_pair(s = ((char)i), i));

	string w = "";
	string compressed = "";
	map<string, int>::iterator i1;

	for (char& c : uncompressed)
	{
		/*
		IF STRING + CHARACTER is in dictionary
		STRING = STRING + CHARACTER
		*/
		string wc = w + c;
		if (dictionary.count(wc))
		{
			w = wc;
		}
		else
		{
			/*
			output the code for STRING
			add STRING + CHARACTER to dictionary
			STRING = CHARACTER
			*/

			i1 = dictionary.find(w);
			compressed += to_string(i1->second);
			compressed += " ";
			dictionary.insert(make_pair(wc, dictionary.size()));
			w = c;
		}
	}
	// write remaining output if necessary
	if (!w.empty())
	{
		i1 = dictionary.find(w);
		compressed += to_string(i1->second);
		compressed += " ";
	}
	//Write the encoder dictionary

	ofile.open("Encoder_Dictionary.txt");
	map<string, int>::iterator it;
	for (it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		string s = it->first + ' ' + to_string(it->second) + '\n';
		ofile << s;
	}
	ofile.close();
	return compressed;
}

string Lzw::decode(string compressed)
{
	ofstream ofile;
	map<int, string> dictionary;
	string s = "";
	for (int i = 0; i < 256; i++)
		dictionary.insert(make_pair(i, s = ((char)i)));

	string w = "";
	string decompressed = "";
	int lasts = 0;
	int pos = 0;
	bool finish = false;
	int ct = 256;
	//LOGIC STARTS!
	for (int i = 0; i < compressed.size(); i = lasts)
	{
		pos = compressed.find(" ", i);
		string s;

		if (pos != -1)
		{
			s = compressed.substr(lasts, pos - lasts);
		}
		else
		{
			s = compressed.substr(lasts, compressed.size() - lasts);
			finish = true;
		}
		int k = stoi(s);
		string now;

		/*
		Read NEW_CODE
		ENTRY = get translation of NEW_CODE
		IF ENTRY == NULL
		ENTRY = PREV + PREV[0]
		*/
		if (dictionary.count(k) > 0)
		{
			now = dictionary[k];
			decompressed += dictionary[k];
		}
		else
		{
			now = w + w[0];
			decompressed += w + w[0];
		}

		/*
		output ENTRY
		IF PREV != NULL
		Add PREV + ENTRY[0] to dictionary
		PREV = ENTRY
		*/
		if (w.size() > 0)
		{
			dictionary[ct++] = w + now[0];
		}
		w = now;
		if (pos != -1)
		{
			lasts = pos + 1;
		}
		if (finish)
			break;
	}


	//Write the decoder dictionary
	ofile.open("Decoder_Dictionary.txt");
	map<int, string>::iterator it;
	for (it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		string s = to_string(it->first) + ' ' + (string)it->second + '\n';
		ofile << s;
	}
	ofile.close();
	return decompressed;
}

Lzw::~Lzw()
{
}
