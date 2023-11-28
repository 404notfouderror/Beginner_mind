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