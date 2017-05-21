#include "Utility.h"



Utility::Utility()
{
	char temp = '1';
	for (unsigned int i = 0; i < 54; i++)
	{
		string file = "../binaryFiles/file-page";
		file += temp;
		cout << "for line " << file << endl;
		vector<vector<char> >binary = read_file(file);
		propality_of_zeroes_and_ones(binary);
		//length_of_zeros_codes(binary);
		//length_of_ones_codes(binary);
		count_ones_line(binary);
		temp++;
	}
}


Utility::~Utility()
{
}


vector<vector<char> >Utility::read_file(string file) {
	string s;
	vector<vector<char> >result;
	ifstream in;
	in.open(file);
	if (!in.is_open()) {
		cout << "error opening files" << endl;
		exit(1);
	}
	int index = 0;
	while (!in.eof())
	{
		getline(in, s);
		if (s.size() != 0)
			result.push_back(vector<char>());
		for (int i = 0; i < s.length() && s.length() != 0; i++)
		{
			result[index].push_back(s[i]);
		}
		index++;
	}
	in.close();
	cout << "finsh reading" << endl;
	cout << "the size of the array is " << result.size() << " size of one row is " << result[0].size() << endl;
	return result;
}

//assuming that the file is 8n length
vector<vector<char> > Utility::binary_char_to_ascii(vector<vector<char> > binary) {
	vector<vector<char> >result;
	for (int i = 0; i < binary.size(); i++)
	{
		result.push_back(vector<char>());
		for (int j = 0; j < binary[0].size(); )
		{
			int n = 0, power = 1;
			for (int k = 0; k < 8; k++)
			{
				if (j >= binary[0].size())
					break;
				n += ((binary[i][j] == '1') ? power : 0);
				power *= 2;
				j++;
			}
			result[i].push_back(char(n));
		}
	}
	cout << "finish converting" << endl;
	return result;
}

void Utility::print_vector_vector_char_console(vector<vector<char> > v) {

}

void Utility::print_vector_vector_char_file(vector<vector<char> > v) {
	ofstream out;
	out.open("ascii file.txt");
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[0].size(); j++)
		{
			out << v[i][j];
		}
		out << endl;
	}
	cout << "finish printing to the file";
}

void Utility::propality_of_zeroes_and_ones(vector<vector<char> > v) {
	int total_size = 0, zero = 0, one = 0;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		for (unsigned int j = 0; j < v[0].size(); j++)
		{
			(v[i][j] == '1') ? one++ : zero++;
			total_size++;
		}
	}
	cout << "The number of zeros is " << zero << " propability is " << (float)zero / total_size << endl
		<< " ones is " << one << " propability is " << (float)one / total_size << endl;
}

void Utility::length_of_zeros_codes(vector<vector<char> > v) {
	char temp = '1';
	map<int, int>sum;
	int count = 0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[0].size(); j++)
		{
			if (v[i][j] == '0')
			{
				count++;
			}
			else if (count != 0)
			{
				sum[count]++;
				count = 0;
			}
		}
	}
	count = 0;
	int segments = 0;
	for (auto item : sum) {
		count++;
		segments += item.second;
		cout << "number of zeros " << item.first << " occurred " << item.second << endl;
	}
	cout << "total number of zero pattern " << count << endl;
	cout << "number of segments " << segments << endl;
}

void Utility::length_of_ones_codes(vector<vector<char> > v) {
	char temp = '1';
	map<int, int>sum;
	int count = 0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[0].size(); j++)
		{
			if (v[i][j] == '1')
			{
				count++;
			}
			else if (count != 0)
			{
				sum[count]++;
				count = 0;
			}
		}
	}
	count = 0;
	int segments = 0;
	for (auto item : sum) {
		count++;
		segments += item.second;
		cout << "number of ones " << item.first << " occurred " << item.second << endl;
	}
	cout << "total number of one patterns " << count << endl;
	cout << "number of segments " << segments << endl;
}

void Utility::count_ones_line(vector<vector<char> > v) {
	int count = 0;
	bool flag = true;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		for (unsigned int j = 0; j < v[0].size(); j++)
		{
			if (v[i][j]=='0')
			{
				flag = false;
			}
		}
		if (flag)
		{
			count++;
		}
		flag = true;
	}
	cout << "the count of the lines is " << count << endl;
}