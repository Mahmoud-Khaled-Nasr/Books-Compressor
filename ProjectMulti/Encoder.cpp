#define _CRT_SECURE_NO_WARNINGS
#include "Encoder.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;



Encoder::Encoder()
{
	cnt++;
}

int Encoder::cnt = 0;
bool Encoder::ReadImage(string imagePath)
{
	Mat imageMat = cv::imread(imagePath, CV_LOAD_IMAGE_COLOR);
	if (imageMat.empty())
		return false;

	//Grayscale matrix
	Mat grayscaleMat(imageMat.size(), CV_8U);

	//Convert BGR to Gray
	cvtColor(imageMat, grayscaleMat, CV_BGR2GRAY);

	//Binary image
	Mat binaryMat(grayscaleMat.size(), grayscaleMat.type());

	//Apply thresholding
	threshold(grayscaleMat, binaryMat, 100, 255, cv::THRESH_BINARY);

	this->binaryMatix = binaryMat;

	this->convertBinaryMatrix2BoolMatrix(imageMat);

	this->convert2BoolMatrixToString();

	return true;
}

void Encoder::encode2nd(string encodedFilePath,string encode2nd)
{
	string s;
	ifstream file;
	file.open(encodedFilePath);
	for (string line; getline(file, line);)
	{
		if (line == to_string(bMat[0].size()) + 'W')
		{
			s += '1';
		}
		else
		{
			s += line;
		}
		s += '\n';
	}
	file.close();
	ofstream o;
	o.open(encode2nd);
	o << s;
	o.close();
}
void Encoder::runLengthEncoding(string encodingFilePath)
{
	ofstream file;
	file.open(encodingFilePath);
	char B = 'B', W = 'W';
	for (int i = 0; i < bMat.size(); i++)
	{
		int cb = 0, cw = 0, lst = 0;
		for (int j = 0; j < bMat[i].size() - 1; j++)
		{
			if (bMat[i][j] != bMat[i][j + 1])
			{
				file << j - lst + 1 << (bMat[i][j] ? W : B);
				lst = j + 1;
			}
		}
		if (bMat[i].size() - lst > 0)
		{
			file << bMat[i].size() - lst << (bMat[i][bMat[i].size() - 1] ? W : B);
		}
		file << endl;
	}
	file.close();
}


Encoder::~Encoder()
{
}

void Encoder::convertBinaryMatrix2BoolMatrix(Mat imageMat)
{
	bMat.resize(imageMat.rows);
	for (int i = 0; i < bMat.size(); i++)
	{
		bMat[i].resize(imageMat.cols);
	}
	//cout << imageMat.rows << "\n" << imageMat.cols;
	for (int i = 0; i<binaryMatix.rows; i++)
	{
		for (int j = 0; j<binaryMatix.cols; j++)
		{
			bMat[i][j] = binaryMatix.at<uchar>(i, j);
		}
	}

	ofstream file;
	file.open("../binaryFiles/file-page" + to_string(cnt));
	for (int i = 0; i<binaryMatix.rows; i++)
	{
		for (int j = 0; j<binaryMatix.cols; j++)
		{
			file << bMat[i][j];
		}
		file << endl;
	}
	file.close();
}

void Encoder::convert2BoolMatrixToString()
{
	messege = "";
	char temp;
	int width = bMat[0].size();
	temp = (char)(width / 256);
	messege += temp;
	messege += (char)(width - (int)temp * 256);
	int length = bMat.size();
	temp = (char)(length / 256);
	messege += temp;
	messege += (char)(length - (int)temp * 256);
	messege += '\n';
	for (int i = 0; i < bMat.size(); i++)
	{
		for (int j = 0; j < bMat[0].size(); j++)
		{
			messege += (bMat[i][j]) ? '1' : '0';
		}
	}
	messege += '\n';
}
