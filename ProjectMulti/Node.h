#ifndef _NODE_H
#define _NODE_H
#include <string>
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
#endif