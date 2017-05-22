#pragma once
#include <map>
#include <vector>
#include <set>
#include <string>
#include<algorithm>
#include <fstream>
#include <iostream>
#include "Algo.h"
#include "Symbol.h"

using namespace std;

struct Node {
	// symbol only meaningful if the node is a leaf node
	char symbol; //[Note]: symbol here should be of type char not "Symbol" struct
				 //        because it willl be sent later to reciever
				 //		   which should not anything else other than the symbol and codeword
				 //		   without knowing the probabilies
				 // the binary codeword of the symbol
	string codeWord;

	// the left node
	Node* left;
	//the right node
	Node* right;
	// probability
	float probability;
};


class Huffman :
	public Algo
{
public:
	vector<Symbol> symbols;
	Node* tree;

	// you can add a map data member that mapes: <symbol char, its codeword> 
	// or use the tree only (as you like)
	//..
	map<string, char> hesham;
	map<char, string> codeTable;
	map<char, float> codeTableProbability;
	void traverseTree(Node * ttree, string s);
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