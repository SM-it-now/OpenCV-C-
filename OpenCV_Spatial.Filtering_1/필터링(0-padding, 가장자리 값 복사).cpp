#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;


int main() {
	Mat image = imread("d:/ch2/lenna.jpg", IMREAD_GRAYSCALE);

	float weights[] = {
		1 / 9.0F, 1 / 9.0F, 1 / 9.0F,
		1 / 9.0F, 1 / 9.0F, 1 / 9.0F,
		1 / 9.0F, 1 / 9.0F, 1 / 9.0F
	};

	Mat mask(3, 3, CV_32F, weights);
	Mat blur;
	// 0 - padding 방법
	// filter2D(image, blur, -1, mask, Point(-1, 1), 0, BORDER_CONSTANT);

	// 가장자리 값 복사
	filter2D(image, blur, -1, mask, Point(-1, 1), 0, BORDER_REPLICATE);
	blur.convertTo(blur, CV_8U);

	imshow("image", image);
	imshow("blur", blur);
	waitKey(0);
	return 0;
}
