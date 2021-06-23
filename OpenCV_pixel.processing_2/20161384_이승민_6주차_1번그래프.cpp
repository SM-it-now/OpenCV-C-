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
		if (i <= 100)				// i가 100미만일 경우 i = 0, 100일 경우 i = 1.
			p[i] = (i / 100) * 100;
		else (i > 100);				// i 가 101부터는 i를 100으로 나눈 나머지를 p[i]값에 저장한다.
			p[i] = (i % 100 + 1);




	Mat img2;
	LUT(img1, table, img2);

	imshow("New Image", img2);
	waitKey(0);

	return 0;
}
