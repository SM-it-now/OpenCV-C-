#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

int main()
{
	Mat img1 = imread("d:/ch2/Lenna.jpg", IMREAD_GRAYSCALE);
	imshow("Original Image", img1);

	Mat table(1, 256, CV_8U);	// ��

	uchar* p = table.ptr();
	int i = 0;
	for (i = 0; i < 256; ++i)     // i�� 0 ~ 256���� Ž���Ѵ�.
		if (i <= 100)				// i�� 100�̸��� ��� i = 0, 100�� ��� i = 1.
			p[i] = (i / 100) * 100;
		else (i > 100);				// i �� 101���ʹ� i�� 100���� ���� �������� p[i]���� �����Ѵ�.
			p[i] = (i % 100 + 1);




	Mat img2;
	LUT(img1, table, img2);

	imshow("New Image", img2);
	waitKey(0);

	return 0;
}
