#include <opencv2/opencv.hpp>
#include "Decoder.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
using namespace cv;
 
 
Decoder::Decoder()
{
}
 
void Decoder::runLengthDecoding(string encodedFilePath)
{
	ifstream file;
	file.open(encodedFilePath);
	string line;
	while (file >> line)
	{
		int lst = 0;
		vector<bool>vec;
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == 'W')
			{
				for (int j = 0; j < stoi(line.substr(lst, i - lst)); j++)
					vec.push_back(true);
				lst = i + 1;
			}
			else if (line[i] == 'B')
			{
				for (int j = 0; j < stoi(line.substr(lst, i - lst)); j++)
					vec.push_back(false);
				lst = i + 1;
			}
		}
		this->bMat.push_back(vec);
	}
	file.close();
}
 
void Decoder::writeDecodedImage(string decodedFilePath)
{
	Mat Image((int)bMat.size(), (int)bMat[0].size(), CV_8UC1, 255);
	for (int i = 0; i < bMat.size(); ++i)
		for (int j = 0; j < bMat[i].size(); ++j)
			Image.at<uchar>(i, j) = this->bMat[i][j] ? 255 : 0;
	imwrite(decodedFilePath, Image);
}
 
 
Decoder::~Decoder()
{
}