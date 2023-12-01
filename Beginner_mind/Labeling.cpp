#include "mind.h"

/*
���̺�( labeling ) �̶�?

������ ���� ���� ���� �ȼ����� �ϳ��� �׷����� �����ִ� �۾��̴�.

���� ���ؼ� ����ȭ �̹������� ��踦 �̷� ������ �̸�(����)�� �ο��ϴ� �۾��̴�.
*/

bool Labeling()
{

	Mat img = imread("image/bacteria.tif");

	Mat img_resize;
	resize(img, img_resize, Size(img.cols * 3, img.rows * 3));

	Mat img_gray;
	cvtColor(img_resize, img_gray, COLOR_BGR2GRAY);

	Mat img_threshold;
	threshold(img_gray, img_threshold, 100, 255, THRESH_BINARY_INV);

	Mat img_labels, stats, centroids;
	int numOfLables = connectedComponentsWithStats(img_threshold, img_labels, stats, centroids, 8, CV_32S);

	for (int i = 1; i < numOfLables; i++)
	{
		int area = stats.at<int>(i, CC_STAT_AREA);
		int left = stats.at<int>(i, CC_STAT_LEFT);
		int top = stats.at<int>(i, CC_STAT_TOP);
		int width = stats.at<int>(i, CC_STAT_WIDTH);
		int height = stats.at<int>(i, CC_STAT_HEIGHT);

		rectangle(img_resize, Point(left, top), Point(left + width, top + height), Scalar(0, 255, 0), 1);
		putText(img_resize, to_string(i), Point(left + 20, top + 20), FONT_HERSHEY_SCRIPT_SIMPLEX, 1, Scalar(0, 0, 0), 3);
	}

	while (true)
	{
		imshow("Result Image", img);
		imshow("Image gray", img_gray);
		imshow("Image threshold", img_threshold);
		imshow("Image resize", img_resize);
		

		if (waitKey(100) == 27)
			break;
	}

	return true;
}