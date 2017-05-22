#pragma once
#include <iostream>

using namespace std;

class CompressionRatio
{
	double m_total_size, m_encoded_size;
public:
	CompressionRatio();
	~CompressionRatio();
	void update_ratio(double total_size, double encoded_size);
	double get_ratio();
};

