#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;


// 평균값 필터링
int main() {
	Mat src = imread("D:/ch2/Lenna.jpg");
	Mat dst_1;
	Mat dst_2;
	
	//// 3 * 3의 평균값 필터링
	//blur(src, dst_1, Size(3, 3));
	//imshow("source", src);
	//imshow("result", dst_1);

	// 11 * 11의 평균값 필터링
	blur(src, dst_2, Size(11, 11));
	imshow("source", src);
	imshow("result", dst_2);

	waitKey(0);
	return 0;
}