#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat src = imread("d:/ch2/lenna.jpg", IMREAD_GRAYSCALE);
	Mat dst = Mat::zeros(Size(src.cols * 2, src.rows * 2), src.type());

	for (int y = 0; y < dst.rows; y++) {
		for (int x = 0; x < dst.cols; x++) {
			const int newX = x / 1.5;
			const int newY = y / 1.5;
			dst.at<uchar>(y, x) = src.at<uchar>(newY, newX);
		}
	}

	imshow("Image", src);
	imshow("Scaled", dst);
	waitKey(0);
	return 1;

	

}
