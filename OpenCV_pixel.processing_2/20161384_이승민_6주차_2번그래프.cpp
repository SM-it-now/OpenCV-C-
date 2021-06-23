#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

int main()
{
	Mat img1 = imread("d:/ch2/Lenna.jpg", IMREAD_GRAYSCALE);
	imshow("Original Image", img1);

	Mat table(1, 256, CV_8U);	// ①

	uchar* p = table.ptr();
	int i = 0;
	for (i = 0; i < 256; ++i)     // i가 0 ~ 256까지 탐색한다.
		if (i >= 100 && i <= 192)
			p[i] = 0;
		else
			p[i] = i;



	Mat img2;
	LUT(img1, table, img2);

	imshow("New Image", img2);
	waitKey(0);

	return 0;
}
