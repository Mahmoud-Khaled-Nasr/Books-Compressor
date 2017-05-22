#ifndef _HUFFMAN_H
#define _HUFFMAN_H
#include <map>
#include <vector>
#include <set>
#include <string>
#include<algorithm>
#include <fstream>
#include <iostream>
#include "Algo.h"
#include "Symbol.h"
#include "Node.h"

using namespace std;



class Huffman :
	public Algo
{
public:
	Nodee * tree;
	vector<Symbol> symbols;
	

	// you can add a map data member that mapes: <symbol char, its codeword> 
	// or use the tree only (as you like)
	//..
	map<string, char> hesham;
	map<char, string> codeTable;
	map<char, float> codeTableProbability;
	void traverseTree(Nodee * ttree, string s);
	void buildTree(vector<Symbol>& senderSymbols);
	void printCodeTable(string codeTableFile);
	float CalcAvgCWLength();
	Huffman();
	~Huffman();
	virtual string encode(string message);
	virtual string decode(string encoded_messege);
	void CalculateProbabilities(string message);
	float CalculateEntropy();
	string encode_huffman(string input_message);
};

#endif
