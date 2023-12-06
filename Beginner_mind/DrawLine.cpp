#include "mind.h"

void DrawMouseEvent(int nEvent, int nX, int nY, int nflags, void* userdata)
{
	static Point prevPoint(-1, -1);

		if (nEvent == EVENT_LBUTTONDOWN)
		{
			prevPoint = Point(nX, nY);
		}
		else if (nEvent == EVENT_LBUTTONUP)
		{
			prevPoint = Point(-1, -1);
		}
		else if (nEvent == EVENT_MOUSEMOVE && (nflags & EVENT_FLAG_LBUTTON))
		{
			Point currentPoint(nX, nY);

			if (prevPoint.x >= 0 && prevPoint.y >= 0)
			{
				line(*static_cast<Mat*>(userdata), prevPoint, currentPoint, Scalar(0, 0, 255), 2);
				prevPoint = currentPoint;
				imshow("MouthEvent", *static_cast<Mat*>(userdata));
			}
		}
}

/*


#if 1
Rect reObj(100, 100, 50, 50);
bool isDragging = false;
Point2i clickPoint;
# endif

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


*/