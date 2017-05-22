#include "Huffman.h"

bool operator< (const pair<int, Nodee*> p1, const pair<int, Nodee*> p2)
{
	// this function is used in the sorting function 
	return p1.first < p2.first;
}


void Huffman::traverseTree(Nodee * ttree, string s)
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
	multiset<pair<int, Nodee*>> setSymbols;
	for (std::vector<Symbol>::iterator it = senderSymbols.begin(); it != senderSymbols.end(); ++it) {
		Nodee* n = new Nodee();
		n->symbol = ((Symbol)(*it)).value;
		n->left = NULL;
		n->right = NULL;
		setSymbols.insert(pair<int, Nodee*>(((Symbol)(*it)).frequency, n));
		codeTableProbability.insert(pair<char, float>(n->symbol, ((Symbol)(*it)).probability));
	}
	while (setSymbols.size()> 1) {
		multiset<pair<int, Nodee*>>::iterator firstIt = setSymbols.begin();
		multiset<pair<int, Nodee*>>::iterator secondIt = ++setSymbols.begin();
		Nodee * n = new Nodee();
		n->left = ((pair<int, Nodee*>)(*firstIt)).second;
		n->right = ((pair<int, Nodee*>)(*secondIt)).second;
		n->probability = 0.0;
		int freq = ((pair<int, Nodee*>)(*firstIt)).first + ((pair<int, Nodee*>)(*secondIt)).first;
		setSymbols.erase(firstIt);
		setSymbols.erase(secondIt);
		setSymbols.insert(pair<int, Nodee*>(freq, n));
	}
	if (setSymbols.size() == 1)
		tree = ((pair<int, Nodee*>)(*setSymbols.begin())).second;
}

void Huffman::printCodeTable(string &message)
{
	for (auto i : this->codeTable) {
		message += i.first;
		message += " " + i.second + " ";
	}
	message += '\n';
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
	split_message(message);
	string prefixOfMsg = "";
	CalculateProbabilities(m_message);
	cout << "the entropy" << CalculateEntropy()<<endl;
	buildTree(symbols);
	string result = encode_huffman(m_message);
	cout << "the average code length" << CalcAvgCWLength()<<endl;
	result = m_prefix + result;
	
	return result;
}

string Huffman::decode(string encoded_message)
{
	split_message(encoded_message);
	string curSub;
	string msg=m_prefix;
	int j = 1;
	int k = 0;
	for (int i = 0; i < m_message.size() && m_message[i]!='\n'; i++)
	{
		curSub = m_message.substr(i, j);
		if (hesham.count(curSub) > 0) {
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
