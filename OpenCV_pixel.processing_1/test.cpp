#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;


int main()
{
	Mat img = imread("d:/ch2/lenna.jpg", IMREAD_GRAYSCALE);
	imshow("Original Image", img);

	for (int r = 0; r < img.rows; r++) // 화소를 순차적으로 접근
		if (r == 50)			// 행이 50일때,
			for (int c = 0; c < img.cols; ++c)
				img.at<uchar>(r, c) = saturate_cast<uchar>(img.at<uchar>(r, c) + 255); // 화소의 값을 255더하지만 오버플로 되지 않게 함수 사용.

	imshow("New Image", img);
	waitKey(0);
	return 0;
}