//============================================================================
// Name        : Counting.cpp
// Author      : Alonso Loaiza Pereira
// Version     :
// Copyright   : GNU GPL 3.0
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <opencv/cv.h>
#include <opencv2/highgui/highgui.hpp>

int main()
{
	char* windowName = "HelloWorldWindow";
	cvNamedWindow(windowName,0x01);
	IplImage* img = cvCreateImage(cvSize(0x96,0x32),IPL_DEPTH_8U,0x01);
	CvFont font;
	double hScale = 0x01;
	double vScale = 0x01;
	int lineWidth = 0x01;
	cvInitFont(&font,CV_FONT_HERSHEY_COMPLEX_SMALL|CV_AA,hScale,vScale,0x00,lineWidth);
	cvPutText(img,"Hello World.",cvPoint(0x00,0x1E),&font,cvScalar(0x00,0x00,0x00));
	cvShowImage(windowName,img);
	cvWaitKey();
	return 0;
}
