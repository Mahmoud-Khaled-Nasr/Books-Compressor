#ifndef _ENCODER_H
#define _ENCODER_H
#include<vector>
#include<string>
#include<opencv2/opencv.hpp>
#include "Utility.h"
#include "Rle.h"
#include "Algo.h"
#include "Lzw.h"
#include "Huffman.h"
using namespace std;
using namespace cv;

class Encoder
{
	string imgPath;
	Mat binaryMatix;
	int static cnt;
public:
	vector<vector<bool>> bMat;
	string messege;
public:
	Encoder();

	bool ReadImage(string imagePath);
	
	void runLengthEncoding(string encodingFilePath);
	void encode2nd(string encodedFilePath, string encode2nd);

	~Encoder();
private:
	void convertBinaryMatrix2BoolMatrix(Mat imageMat);
	void convert2BoolMatrixToString();
};
#endif