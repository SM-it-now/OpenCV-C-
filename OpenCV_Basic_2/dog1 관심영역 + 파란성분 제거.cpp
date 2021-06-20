
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

Mat img, roi;
int mx1, my1, mx2, my2;   // 마우스로 지정한 사각형의 좌표
bool cropping = false;    // 사각형 선택 중임을 나타내는 플래그 변수


// 마우스로 이벤트가 발생하면 호출되는 콜백 함수
void onMouse(int event, int x, int y, int flags, void* param)
{
	if (event == EVENT_LBUTTONDOWN) {                 // 마우스 왼쪽 버튼을 누르면 발생
		mx1 = x;									  // 사각형의 좌측 상단 좌표 저장
		my1 = y;
		cropping = true;
	}
	else if (event == EVENT_LBUTTONUP) {			  // 마우스 왼쪽 버튼에서 손을 떼면 발생
		mx2 = x;									  // 사각형의 우측 하단 좌표 저장
		my2 = y;	
		cropping = false;
		rectangle(img, Rect(mx1, my1, mx2 - mx1, my2 - my1), Scalar(255, 0, 0), 2);    // 마우스 이벤트 사각형 테두리 색 및 굵기

		imshow("image", img);
	}
}

int main() {
	img = imread("D:/ch2/dog.jpg");
	imshow("image", img);
	Mat clone = img.clone();				// 복사본을 만들어서 관심영역을 파일로 저장하게끔 가능

	setMouseCallback("image", onMouse);

	while (1) {
		int key = waitKey(100);
		if (key == 'q') break;									// 'q'를 누르면 종료
		else if (key == 'c') {									// 'c'를 누르면 저장
			roi = clone(Rect(mx1, my1, mx2 - mx1, my2 - my1));
			roi -= Scalar(255, 0, 0);                  // dog1.jpg 로 저장할 roi함수에 파란 성분을 모두 제거
			imwrite("D:/ch2/dog1.jpg", roi);
		}
	}

	return 0;
}

