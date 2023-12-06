#include "mind.h"

bool CVRange()
{
	Mat image = imread("image/balls.jpg");
	Mat img_hsv;

	cvtColor(image, img_hsv, COLOR_BGR2HSV);

	Mat yellow_mask, yellow_img;

	Scalar low_yellow = Scalar(20, 20, 100);
	Scalar high_yellow = Scalar(32, 255, 255);

	inRange(img_hsv, low_yellow, high_yellow, yellow_mask);
	bitwise_and(image, image, yellow_img, yellow_mask);

	while (true)
	{
		imshow("Original", image);
		imshow("Yellow Image", yellow_img);
		imshow("Mask", yellow_mask);

		if (waitKey(100) == 27)
			break;
	}

	return false;
}
