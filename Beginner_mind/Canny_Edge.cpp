#include "mind.h"

bool Canny()
{
	// imagae Set
	Mat img = imread("image/sample.jpg");

	// gray Scale
	Mat img_gray;
	cvtColor(img, img_gray, COLOR_BGR2GRAY);

	// image Edge
	Mat img_org_edge;
	Mat img_gray_edge;

	// Canny Func src, dst, threshold1, threshold2
	Canny(img, img_org_edge, 100, 300);
	Canny(img_gray, img_gray_edge, 100, 300);

	// Display
	while (true)
	{
  		imshow("Original", img);
		imshow("Orginal Edge", img_org_edge);
		imshow("GrayScale Edge", img_gray_edge);
		
		if (waitKey(100) == 27)
			break;
	}

	return true;
}