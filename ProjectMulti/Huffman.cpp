#include "Huffman.h"

bool operator< (const pair<int, Node*> p1, const pair<int, Node*> p2)
{
	// this function is used in the sorting function 
	return p1.first < p2.first;
}


void Huffman::traverseTree(Node * ttree, string s)
{
	// this function traverse the tree to build the code table for symbol
	if (ttree->left != NULL) {
		traverseTree(ttree->left, s + "0");
	}
	if (ttree->right != NULL) {
		traverseTree(ttree->right, s + "1");
	}
	if ((ttree->left == NULL) && (ttree->left == NULL)) {
		codeTable.insert(pair<char, string>(ttree->symbol, s));
		hesham.insert(pair<string, char>(s, ttree->symbol));
	}
}

void Huffman::buildTree(vector<Symbol>& senderSymbols)
{
	multiset<pair<int, Node*>> setSymbols;
	for (std::vector<Symbol>::iterator it = senderSymbols.begin(); it != senderSymbols.end(); ++it) {
		Node* n = new Node();
		n->symbol = ((Symbol)(*it)).value;
		n->left = NULL;
		n->right = NULL;
		setSymbols.insert(pair<int, Node*>(((Symbol)(*it)).frequency, n));
		codeTableProbability.insert(pair<char, float>(n->symbol, ((Symbol)(*it)).probability));
	}
	while (setSymbols.size()> 1) {
		multiset<pair<int, Node*>>::iterator firstIt = setSymbols.begin();
		multiset<pair<int, Node*>>::iterator secondIt = ++setSymbols.begin();
		Node * n = new Node();
		n->left = ((pair<int, Node*>)(*firstIt)).second;
		n->right = ((pair<int, Node*>)(*secondIt)).second;
		n->probability = 0.0;
		int freq = ((pair<int, Node*>)(*firstIt)).first + ((pair<int, Node*>)(*secondIt)).first;
		setSymbols.erase(firstIt);
		setSymbols.erase(secondIt);
		setSymbols.insert(pair<int, Node*>(freq, n));
	}
	if (setSymbols.size() == 1)
		tree = ((pair<int, Node*>)(*setSymbols.begin())).second;
}

void Huffman::printCodeTable(string codeTableFile)
{
	ofstream outfile;
	outfile.open(codeTableFile, std::ofstream::out);
	for (std::map<char, string>::iterator it = codeTable.begin(); it != codeTable.end(); it++) {
		outfile << ((pair<char, string>)(*it)).first << " " << ((pair<char, string>)(*it)).second << endl;
	}
}

float Huffman::CalcAvgCWLength()
{
	float avgL = 0;
	for (auto it : this->codeTable) {
		avgL += int(it.second.size())*this->codeTableProbability[it.first];
	}
	return avgL;
}

Huffman::Huffman()
{
}


Huffman::~Huffman()
{
}

string Huffman::encode(string message)
{
	string prefixOfMsg = "";
	int cendl = 0;
	for (int i = 0; i < message.size(); i++)
	{
		if (message[i] == '\n')cendl++;
		if (cendl == 2)
		{
			prefixOfMsg += message[i];
			message = message.substr(i + 1, message.size() - i - 1);
			break;
		}
		prefixOfMsg += message[i];
	}
	CalculateProbabilities(message);
	buildTree(symbols);
	string result = prefixOfMsg + encode_huffman(message);
	return result;
}

string Huffman::decode(string encoded_message)
{
	string curSub;
	string msg;
	int j = 1;
	int k = 0;
	for (int i = 0; i < encoded_message.size(); i++)
	{
		curSub = encoded_message.substr(i, j);
		if (hesham.count(curSub) != 0) {
			msg += hesham[curSub];
			i = k + j - 1;
			k = i + 1;
			j = 1;
		}
		else {
			i--;
			j++;
		}
	}
	return msg;
}

void Huffman::CalculateProbabilities(string message)
{
	map<char, int>frq;
	for (int i = 0; i < message.size(); i++)
	{
		frq[message[i]]++;
	}
	for (map<char, int>::iterator it = frq.begin(); it != frq.end(); it++)
	{
		Symbol smp(it->first, it->second, it->second / (float)message.size());
		symbols.push_back(smp);
	}
}

float Huffman::CalculateEntropy()
{
	float h = 0;
	for (int i = 0; i < this->symbols.size(); i++)
	{
		h += (symbols[i].probability*log2(1.0 / symbols[i].probability));
	}
	return h;
}

string Huffman::encode_huffman(string input_message)
{
	traverseTree(this->tree, "");
	string msg;
	string line = input_message;
	for (int i = 0; i < line.size(); i++)
	{
		msg += this->codeTable[line[i]];
	}
	return msg;
}
