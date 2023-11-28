#include "mind.h"

int main()
{
	/*
	// image file Set
	Mat img = imread("img.jpg");

	// image View & Print
	imshow("img", img);

	// Key Wait
	waitKey(0);
	

	// View Window Set
	namedWindow("Yukina", WINDOW_AUTOSIZE);

	// Image Path Set
	string path = ".\\img.jpg";

	// Mat Image Set
	Mat image = imread(path, IMREAD_ANYCOLOR);

	// image Empty Extention
	if (image.empty())
	{
		cerr << "Image Loading Fail!" << endl;
		return -1;
	}

	// File Info
	unsigned char* pData = image.data;
	float fwidth	= image.cols; 
	float fheight	= image.rows;
	float fchannel	= image.channels();
	float fdepth	= image.depth();
	float ftype		= image.type();

	// File Info Print
	cout << "width"		<< fwidth	<< endl;
	cout << "height"	<< fheight	<< endl;
	cout << "channel"	<< fchannel << endl;
	cout << "depth"		<< fdepth	<< endl;
	cout << "type"		<< ftype	<< endl;

	// Input Ket Wait
	while (true)
	{
		imshow("Yukina", image);
		
		if (waitKey(100) == 27)
			break;
	}
	*/

	ROI_Func();

	return 0;
}