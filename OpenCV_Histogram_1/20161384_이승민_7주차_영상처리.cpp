#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;


void hist1() {			//   콘트라스트 이전의 원본 "contrast.jpg" 의 히스토그램 함수
	Mat image = imread("d:/ch2/contrast.jpg");
	vector<Mat> bgr_planes;	// 영상들의 벡터 
	split(image, bgr_planes);	// 입력 영상을 색상별로 분리한다.
	int histSize = 256;	// 히스토그램에서 사용되는 상자의 개수
	float range[] = { 0, 256 }; 	// 화소값의 범위
	const float* histRange = { range };
	bool uniform = true, accumulate = false;
	Mat b_hist, g_hist, r_hist;

	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);

	// 막대그래프가 그려지는 영상을 생성한다. 
	int hist_w = 512, hist_h = 400;
	int bin_w = cvRound((double)hist_w / histSize);	// 상자의 폭
	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));

	// 값들이 영상을 벗어나지 않도록 정규화한다. 
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	// 히스토그램의 값을 막대로 그린다. 
	for (int i = 0; i < 255; i++) {
		line(histImage, Point(bin_w * (i), hist_h),
			Point(bin_w * (i), hist_h - b_hist.at<float>(i)),
			Scalar(255, 0, 0));
		line(histImage, Point(bin_w * (i), hist_h),
			Point(bin_w * (i), hist_h - g_hist.at<float>(i)),
			Scalar(0, 255, 0));
		line(histImage, Point(bin_w * (i), hist_h),
			Point(bin_w * (i), hist_h - r_hist.at<float>(i)),
			Scalar(0, 0, 255));
	}
	imshow("Ohis image", histImage);
}



void hist2(float alpha, int beta) {		//  콘트라스트 이후의 "contrast.jpg" 의 히스토그램 함수
	Mat image = imread("d:/ch2/contrast.jpg");
	Mat oimage = Mat::zeros(image.size(), image.type());
	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++) {
			for (int c = 0; c < 3; c++) {
				oimage.at<Vec3b>(y, x)[c] =
					saturate_cast<uchar>(alpha * (image.at<Vec3b>(y, x)[c]) + beta);
			}
		}
	}

	vector<Mat> bgr_planes;	// 영상들의 벡터 
	split(oimage, bgr_planes);	// 입력 영상을 색상별로 분리한다.
	int histSize = 256;	// 히스토그램에서 사용되는 상자의 개수
	float range[] = { 0, 256 }; 	// 화소값의 범위
	const float* histRange = { range };
	bool uniform = true, accumulate = false;
	Mat b_hist, g_hist, r_hist;

	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);

	// 막대그래프가 그려지는 영상을 생성한다. 
	int hist_w = 512, hist_h = 400;
	int bin_w = cvRound((double)hist_w / histSize);	// 상자의 폭
	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));

	// 값들이 영상을 벗어나지 않도록 정규화한다. 
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	// 히스토그램의 값을 막대로 그린다. 
	for (int i = 0; i < 255; i++) {
		line(histImage, Point(bin_w * (i), hist_h),
			Point(bin_w * (i), hist_h - b_hist.at<float>(i)),
			Scalar(255, 0, 0));
		line(histImage, Point(bin_w * (i), hist_h),
			Point(bin_w * (i), hist_h - g_hist.at<float>(i)),
			Scalar(0, 255, 0));
		line(histImage, Point(bin_w * (i), hist_h),
			Point(bin_w * (i), hist_h - r_hist.at<float>(i)),
			Scalar(0, 0, 255));
	}
	imshow("Nhis image", histImage);
}





int main(int argc, char** argv)
{
	double alpha = 1.0;
	int beta = 0;
	Mat image = imread("d:/ch2/contrast.jpg");

	Mat oimage = Mat::zeros(image.size(), image.type());
	cout << "알파값을 입력하시오: [1.0-3.0]: "; cin >> alpha;
	cout << "베타값을 입력하시오: [0-100]: ";    cin >> beta;
	for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++) {
			for (int c = 0; c < 3; c++) {
				oimage.at<Vec3b>(y, x)[c] =
					saturate_cast<uchar>(alpha * (image.at<Vec3b>(y, x)[c]) + beta);
			}
		}
	}




	imshow("Original Image", image);
	hist1();		// hist1함수에서 원본 사진의 히스토그램을 출력.
	//imshow("Ohis image", histImage);
	imshow("New Image", oimage);
	hist2(alpha, beta);		// hist2함수에서 alpha, beta값을 참조하여 콘트라스트 처리를 한 후의 사진의 히스토그램을 출력.
	//imshow("Nhis image", histImage);
	waitKey();
	return 0;
}
