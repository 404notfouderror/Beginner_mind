#include "mind.h"


Rect reObj(100, 100, 50, 50);
bool isDragging = false;
Point2i clickPoint;

void EventTset(int nEvent, int nX, int nY, int nflags, void* userdata)
{

	if (nEvent == EVENT_LBUTTONDOWN)
	{
		if (reObj.contains(Point(nX, nY)))
		{
			isDragging = true;
			clickPoint = Point2i(nX, nY);
		}
	}
	else if (nEvent == EVENT_MOUSEMOVE)
	{
		if (isDragging)
		{
			int nDeltaX = nX - clickPoint.x;
			int nDeltaY = nY - clickPoint.y;

			reObj.x += nDeltaX;
			reObj.y += nDeltaY;

			clickPoint = Point2i(nX, nY);
		}
	}
	else if (nEvent == EVENT_LBUTTONUP)
		isDragging = false;

}

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
	
	// ROI(region of interest)
	if (!ROI_Func())
		return 0;
	
	// rectangle, circle draw
	if (!Draw())
		return 0;

	// Draw Line - mouseEvent
	Mat Image(400, 400, CV_8UC3, Scalar(255, 255, 255));
	imshow("MouthEvent", Image);
	setMouseCallback("MouthEvent", DrawMouseEvent, &Image);

	waitKey(0);
	

	if (!Labeling())
		return 0;

	if (!Canny())
		return 0;

	*/

	Mat Image(400, 400, CV_8UC3, Scalar(255, 255, 255));
	namedWindow("Drag Rectangle", WINDOW_AUTOSIZE);
	setMouseCallback("Drag Rectangle", EventTset); 

	while (true)
	{
		Mat clone = Image.clone();
		rectangle(clone, reObj, Scalar(0, 0, 255));
		imshow("Drag Rectangle", clone);

		char key = waitKey(10);

		if (key == 27)
			break;
	}
	
	return 0;
}

