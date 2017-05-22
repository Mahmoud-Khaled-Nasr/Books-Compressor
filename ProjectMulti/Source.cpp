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

/*int main() {
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
			Algo* lzw = new Lzw();

			string encoded = rle->encode(message);
			encoded = lzw->encode(encoded);
			encoded = huffman->encode(encoded);
			utility->print_encoded_string_in_file(encoded,"../rle lzw huffman/file-page"+to_string(i)+".txt");
			string decoded = huffman->decode(encoded);
			decoded = lzw->decode(decoded);
			decoded = rle->decode(decoded);
			
			
			///string huffman_decoded = huffman->decode(huffman_encoded);
			if (utility->compare_strings(message, decoded))
			{
				cout << "compression success" << endl;
			}
			else
			{
				cout << "compression failed" << endl;
			}
		}
	}
}*/

int main() {

}