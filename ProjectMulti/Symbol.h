#ifndef _SYMBOL_H
#define _SYMBOL_H

// Define a symbol struct here to hold the symbol (from a to z)
// and its probability/frequency
struct Symbol {
	char value;
	int frequency;
	float probability;

	Symbol(char val, int frq, float prop) {
		value = val;
		frequency = frq;
		probability = prop;
	}
};
#endif
