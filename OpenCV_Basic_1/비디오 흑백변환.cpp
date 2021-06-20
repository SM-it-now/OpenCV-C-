
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
		Mat frame, gray1; // �溮��ȯ�� �� ������ ����
		cap >> frame;
		cvtColor(frame, gray1,CV_BGR2GRAY); // cvtColor()�� �̿��� frame �� CV_BGR2GRAY��麯ȯ �� ����, gray1�� ����
		imshow("gray1", gray1); // imshow()�� �̿��� ��麯ȯ �� gray1�� ���
		if (waitKey(30) >= 0)
			break;
	}
	return 0;
}

