#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat src = imread("D:/ch2/lenna.jpg", IMREAD_GRAYSCALE);
	Mat grad = Mat::zeros(src.size(), src.type());

	int scale = 1;
	int delta = 0;

	Mat grad_x, grad_y, abs_grad_x, abs_grad_y;

	Sobel(src, grad_x, CV_16S, 1, 0, 3, scale, delta, BORDER_DEFAULT);
	Sobel(src, grad_y, CV_16S, 0, 1, 3, scale, delta, BORDER_DEFAULT);

	convertScaleAbs(grad_x, abs_grad_x);
	convertScaleAbs(grad_y, abs_grad_y);

	double thd;
	printf("ThresHold 값을 입력하세요 : ");
	cin >> thd;

	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			if ((abs_grad_y.at<uchar>(i, j) + abs_grad_y.at<uchar>(i, j)) >= thd) {
				grad.at<uchar>(i, j) = 0.5 * abs_grad_y.at<uchar>(i, j) + 0.5 * abs_grad_y.at<uchar>(i, j);
			}
			else if ((abs_grad_y.at<uchar>(i, j) + abs_grad_y.at<uchar>(i, j)) < thd) {
				grad.at<uchar>(i, j) = 0;
			}
		}
	}

	imshow("input", src);
	imshow("output", grad);

	waitKey(0);
	return 0;

}
