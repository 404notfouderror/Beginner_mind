#include "mind.h"

// bool Func <ROI>
bool ROI_Func() {

	Mat img = imread("image/sample.jpg", IMREAD_GRAYSCALE);
	
	// image x, y, width, height
	float fx		= 100;
	float fy		= 50;
	float fwidth	= 0;
	float fheight	= 0;
	
	fwidth  = img.size().width;
	fheight = img.size().height;

	Mat mROI1, mROI2;

	mROI1 = img(Rect(fx, fy, fwidth / 2, fheight / 2));
	//mROI2 = img(Rect(Point(fx, fy), Point(fy, fx)));
	
	// Input Ket Wait
	while (true)
	{
		imshow("sample", img);
		imshow("ROI", mROI1);

		if (waitKey(100) == 27)
			break;
	}
	return true;
}

bool Draw()
{
	// blank Image 빈image 파일 출력
	Mat img(512, 512, CV_8UC3, Scalar(0, 0, 0));
	//  Scalar(B, G, R); RGB가 아닌 GBR 순서

	// Circle 원 그리기
	circle(img, Point(256, 256), 155, Scalar(0, 0, 255), 3, LINE_AA);

	// Rect 사각형 그리기
	rectangle(img, Point(30, 30), Point(150, 145), Scalar(255, 0, 0), FILLED);

	// _--_ Test
	rectangle(img, Point(0, 0), Point(img.size().width, img.size().height), Scalar(0, 255, 255), 4);

	// image Show
	while (true)
	{
		imshow("Image", img);

		if (waitKey(100) == 27)
			break;

	}

	return  true;
}
