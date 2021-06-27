#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;




//int main()
//{
//	Mat src, dst;
//
//	src = imread("d:/ch2/chroma.jpg", IMREAD_COLOR);
//	imshow("Image", src);
//	if (!src.data) { return -1; }
//
//	Mat threshold_image;
//	threshold(src, threshold_image, 100, 255, THRESH_BINARY);
//	//threshold_image = threshold_image + Scalar(0, 0, 250);
//	cvtColor(threshold_image, dst, COLOR_BGR2RGB);
//	imshow("Thresholded", dst);
//	waitKey(0);
//	return 0;
//}

int main()
{
	Mat src, dst;

	src = imread("d:/ch2/chroma.jpg", IMREAD_COLOR);
	imshow("Image", src);
	if (!src.data) { return -1; }

	Mat threshold_image;
	threshold(src, threshold_image, 100, 255, THRESH_BINARY);
	imshow("Thresholded", threshold_image);
	waitKey(0);
	return 0;
}

