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