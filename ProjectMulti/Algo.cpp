#include "Algo.h"



void Algo::split_message(string message)
{
	int start_index = 5;
	m_prefix = message.substr(0, start_index);
	m_message = m_message.substr(start_index, m_message.size() - m_prefix.size());
	m_width = (int)m_message[0] * 256 + (int)m_message[1];
	m_length = (int)m_message[2] * 256 + (int)m_message[3];
}

Algo::Algo()
{
}


Algo::~Algo()
{
}
