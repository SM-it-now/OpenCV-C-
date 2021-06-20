
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main() {
	VideoCapture cap("D:/ch2/trailer.mp4");
	if (!cap.isOpened())
		return -1;

	namedWindow("frame", 1);
	for (;;) {
		Mat frame, gray1; // 흑벽변환을 할 변수를 선언
		cap >> frame;
		cvtColor(frame, gray1,CV_BGR2GRAY); // cvtColor()를 이용해 frame 을 CV_BGR2GRAY흑백변환 한 다음, gray1로 저장
		imshow("gray1", gray1); // imshow()를 이용해 흑백변환 한 gray1을 출력
		if (waitKey(30) >= 0)
			break;
	}
	return 0;
}

