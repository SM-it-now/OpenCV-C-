
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

Mat img, roi;
int mx1, my1, mx2, my2;   // ���콺�� ������ �簢���� ��ǥ
bool cropping = false;    // �簢�� ���� ������ ��Ÿ���� �÷��� ����


// ���콺�� �̺�Ʈ�� �߻��ϸ� ȣ��Ǵ� �ݹ� �Լ�
void onMouse(int event, int x, int y, int flags, void* param)
{
	if (event == EVENT_LBUTTONDOWN) {                 // ���콺 ���� ��ư�� ������ �߻�
		mx1 = x;									  // �簢���� ���� ��� ��ǥ ����
		my1 = y;
		cropping = true;
	}
	else if (event == EVENT_LBUTTONUP) {			  // ���콺 ���� ��ư���� ���� ���� �߻�
		mx2 = x;									  // �簢���� ���� �ϴ� ��ǥ ����
		my2 = y;	
		cropping = false;
		rectangle(img, Rect(mx1, my1, mx2 - mx1, my2 - my1), Scalar(255, 0, 0), 2);    // ���콺 �̺�Ʈ �簢�� �׵θ� �� �� ����

		imshow("image", img);
	}
}

int main() {
	img = imread("D:/ch2/dog.jpg");
	imshow("image", img);
	Mat clone = img.clone();				// ���纻�� ���� ���ɿ����� ���Ϸ� �����ϰԲ� ����

	setMouseCallback("image", onMouse);

	while (1) {
		int key = waitKey(100);
		if (key == 'q') break;									// 'q'�� ������ ����
		else if (key == 'c') {									// 'c'�� ������ ����
			roi = clone(Rect(mx1, my1, mx2 - mx1, my2 - my1));
			roi -= Scalar(255, 0, 0);                  // dog1.jpg �� ������ roi�Լ��� �Ķ� ������ ��� ����
			imwrite("D:/ch2/dog1.jpg", roi);
		}
	}

	return 0;
}

