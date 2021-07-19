#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat src = imread("D:/ch2/city1.jpg", IMREAD_GRAYSCALE);
	Mat dst;
	Mat noise_img = Mat::zeros(src.rows, src.cols, CV_8U);

	randu(noise_img, 0, 255);
	Mat black_img = noise_img < 10;
	Mat white_img = noise_img > 255;

	Mat src1 = src.clone();

	src1.setTo(255, white_img);
	src1.setTo(0, black_img);
	medianBlur(src1, dst, 5);

	imshow("input", src1);
	imshow("output", dst);

	waitKey(0);
	return 0;

}
