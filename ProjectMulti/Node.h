#ifndef _NODE_H
#define _NODE_H
#include <string>

struct Nodee {
	// symbol only meaningful if the node is a leaf node
	char symbol; //[Note]: symbol here should be of type char not "Symbol" struct
				 //        because it willl be sent later to reciever
				 //		   which should not anything else other than the symbol and codeword
				 //		   without knowing the probabilies
				 // the binary codeword of the symbol
	std::string codeWord;

	// the left node
	Nodee* left;
	//the right node
	Nodee* right;
	// probability
	float probability;
};
#endif