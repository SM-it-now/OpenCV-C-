#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main() {
	Mat image = Mat(400, 600, CV_8UC3, Scalar(0, 0, 0));
	image = imread("D:/ch2/hidden pictures.jpg", IMREAD_COLOR);

	circle(image, Point(200, 530), 40, Scalar(0, 0, 255), 2); // mushroom
	circle(image, Point(350, 140), 40, Scalar(0, 0, 255), 2); // feather
	circle(image, Point(150, 220), 40, Scalar(0, 0, 255), 2); // banana
	circle(image, Point(30, 460), 40, Scalar(0, 0, 255), 2); // wishbone
	circle(image, Point(190, 370), 30, Scalar(0, 0, 255), 2); // cap
	circle(image, Point(300, 510), 40, Scalar(0, 0, 255), 2); // worm
	circle(image, Point(145, 295), 20, Scalar(0, 0, 255), 2); // heart
	circle(image, Point(350, 340), 30, Scalar(0, 0, 255), 2); // shoes
	circle(image, Point(235, 300), 30, Scalar(0, 0, 255), 2); // seashell
	circle(image, Point(220, 170), 40, Scalar(0, 0, 255), 2); // trowel
	circle(image, Point(140, 420), 30, Scalar(0, 0, 255), 2); // fishhook
	ellipse(image, Point(85, 200), Point(80, 30), 90, 10, 450, Scalar(0, 0, 255), 2); // ladle
	circle(image, Point(370, 470), 20, Scalar(0, 0, 255), 2); // tack



	if (image.empty()) {
		cout << "영상을 읽을 수 없음" << endl;
	}
	imshow("영상 출력", image);

	waitKey(0);
	return 0;
}