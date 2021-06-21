#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;


int main()
{
	Mat img = imread("d:/ch2/lenna.jpg", IMREAD_GRAYSCALE);
	imshow("Original Image", img);

	for (int r = 0; r < img.rows; r++) // ȭ�Ҹ� ���������� ����
		if (r == 50)			// ���� 50�϶�,
			for (int c = 0; c < img.cols; ++c)
				img.at<uchar>(r, c) = saturate_cast<uchar>(img.at<uchar>(r, c) + 255); // ȭ���� ���� 255�������� �����÷� ���� �ʰ� �Լ� ���.

	imshow("New Image", img);
	waitKey(0);
	return 0;
}