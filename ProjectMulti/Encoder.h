#include<vector>
#include<string>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

class Encoder
{
	string imgPath;
	Mat binaryMatix;
	int static cnt;
public:
	vector<vector<bool>> bMat;
public:
	Encoder();

	bool ReadImage(string imagePath);

	void runLengthEncoding(string encodingFilePath);
	void encode2nd(string encodedFilePath, string encode2nd);

	~Encoder();
private:
	void convertBinaryMatrix2BoolMatrix(Mat imageMat);
};