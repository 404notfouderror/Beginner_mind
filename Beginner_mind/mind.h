#pragma once

#include <iostream>
#include <windows.h>

#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

bool ROI_Func();
bool Draw();
bool Labeling();
bool Canny();

void DrawMouseEvent(int nEvent, int nX, int nY, int nflags, void* userdata);
