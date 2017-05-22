#include "CompressionRatio.h"



CompressionRatio::CompressionRatio()
{
	m_encoded_size = 0;
	m_total_size = 0;
}


CompressionRatio::~CompressionRatio()
{
}

void CompressionRatio::update_ratio(double total_size, double encoded_size)
{
	m_total_size += total_size;
	m_encoded_size += encoded_size;
}

double CompressionRatio::get_ratio()
{
	cout << "the average compression ratio " << m_total_size / m_encoded_size << endl;
	return m_total_size / m_encoded_size;
}

