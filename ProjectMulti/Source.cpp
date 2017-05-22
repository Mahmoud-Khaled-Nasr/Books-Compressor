#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <opencv2/opencv.hpp>
#include <fstream>
#include <vector>
#include "Encoder.h"
#include "Decoder.h"
#include "Utility.h"
#include "Rle.h"
#include "Algo.h"
#include "Lzw.h"
#include "Huffman.h"
#include<time.h>

using namespace cv;
using namespace std;

int summ = 0;

/*int main()
{
	for (int i = 1; i <= 55; i++)
	{
		Encoder* encoder = new Encoder();
		if (encoder->ReadImage("../DataSet/file-page" + to_string(i) + ".jpg"))
		{
			encoder->runLengthEncoding("../CompressedFiles/encodedFile-page" + to_string(i) + ".txt");
			encoder->encode2nd("../CompressedFiles/encodedFile-page" + to_string(i) + ".txt",
				"../C/encodedFile-page" + to_string(i) + ".txt");

			summ += int(encoder->bMat.size()*encoder->bMat[0].size());

			Decoder* decoder = new Decoder();
			decoder->runLengthDecoding("../CompressedFiles/encodedFile-page" + to_string(i) + ".txt");
			decoder->writeDecodedImage("../ImagesAfterDecoding/file-page" + to_string(i) + ".jpg");

			bool flag;
			for (int j = 0; j < encoder->bMat.size(); j++)
			{
				flag = false;
				for (int k = 0; k < encoder->bMat[j].size(); k++)
				{
					if (encoder->bMat[j][k] != decoder->bMat[j][k])
					{
						flag = true;
						cout << "Image #:" << to_string(i) << " is not compressed correctly" << endl;
						break;
					}
				}
				if (flag)break;
			}
			if (!flag)
				cout << "Image #:" << to_string(i) << " is compressed correctly" << endl;

		}
		else
		{
			cout << "ERROR in Reading the Image " + to_string(i) << endl;
		}
	}
	cout << summ << endl;
	return 0;
}*/
inline void getFilesInDirectory(const string& directory, vector<string>& files) {
	string s = "dir " + directory + " -b > dirs.txt";
	system(s.c_str());

	ifstream fin("dirs.txt");

	while (getline(fin, s)) {
		if (s.length() >= 4 && s.substr(s.length() - 4, 4) == ".jpg") {
			string k = "", y;
			for (int i = s.length() - 5; i >= 0 && s[i] != ' '; --i) {
				k += s[i];
			}
			reverse(k.begin(), k.end());
			files.push_back(k);
		}
	}
	remove("dirs.txt");
}
int main() {
	Utility* utility = new Utility();
	//here the remainig code for function getFilesInDirectory
	vector<string> files;
	getFilesInDirectory("DataSet", files);
	int totalTime = 0, encoded_size = 0, total_size = 0;
	double compressedSize = 0, originalSize = 0;

	for (string x : files) 
	{
		int start_s = clock();
		string name = "DataSet/" + x + ".jpg";
		Encoder* encoder = new Encoder();
		if (encoder->ReadImage(name))
		{
			cout << "for file " << name << endl;
			string message = encoder->messege;
			string encoded, decoded;
			//add the compression algorithms here
			Algo*rle = new Rle();
			Algo*huffman = new Huffman();
			Algo*lzw = new Lzw();

			encoded = rle->encode(message);
			decoded = rle->decode(encoded);

			if (utility->compare_strings(message, decoded))
			{
				cout << "compression success" << endl;
				encoded_size += message.size();
				total_size += decoded.size();
			}
			else
			{
				cout << "compression failed" << endl;
			}
		}
		int stop_s = clock();
		totalTime += stop_s - start_s;
		cout << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds "<<endl;
	}
	cout << "the average compression ratio " << (double)(total_size) / encoded_size << endl;
	system("pause");
}