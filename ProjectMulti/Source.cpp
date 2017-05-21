#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <opencv2/opencv.hpp>
#include <fstream>
#include <vector>
#include "Encoder.h"
#include "Decoder.h"
#include "Utility.h"

using namespace cv;
using namespace std;

int summ = 0;

int main()
{
	Utility util;
	cout << "end of code" << endl;
	/*for (int i = 1; i <= 55; i++)
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
	return 0;*/
}