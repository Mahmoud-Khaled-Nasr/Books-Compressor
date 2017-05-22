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
	string message, decoded_string;
	for (int i = 1; i <= 55; i++)
	{
		Encoder* encoder = new Encoder();
		if (encoder->ReadImage("../DataSet/file-page" + to_string(i) + ".jpg"))
		{
			cout << "for file " << "file-page" << to_string(i) << ".jpg" << endl;
			message = encoder->messege;

			Algo* rle = new Rle();
			Huffman* huffman = new Huffman();
			string rle_encoded = rle->encode(message);
			string huffman_encoded = huffman->encode(rle_encoded);
			//Algo*lzw = new Lzw();
			//string lzw_encoded = lzw->encode(rle_encoded_string);
			utility->print_encoded_string_in_file(huffman_encoded,"../rle huffman/file-page"+to_string(i)+".txt");
			string huffman_decoded = huffman->decode(huffman_encoded);
			string rle_decoded = rle->decode(huffman_decoded);
			
			
			///string huffman_decoded = huffman->decode(huffman_encoded);
			if (utility->compare_strings(message, rle_decoded))
			{
				cout << "compression success" << endl;
			}
			else
			{
				cout << "compression failed" << endl;
			}
		}
	}

	//here the remainig code for function getFilesInDirectory
	vector<string> files;
	getFilesInDirectory("DataSet", files);
	int totalTime = 0;
	double compressedSize = 0, originalSize = 0;

	for (string x : files) {
		int start_s = clock();

		string name = "DataSet/" + x + ".jpg";
		string newimage = "Decompressed/" + x + "new" + ".jpg";
		string data = "Compressed/" + x + "_encoded" + ".txt";
		int stop_s = clock();
		totalTime += stop_s - start_s;
		cout << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds ";
}