/*
 * Manager.hpp
 *
 *  Created on: 7/4/2015
 *      Author: alonso
 */

#ifndef MANAGER_HPP_
#define MANAGER_HPP_

#include <opencv/cv.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

class Manager
{

public:

	Manager();
	virtual ~Manager();
	int iniciarPrograma(int pIdCamara);

private:

	VideoCapture* _VideoCamara;
};

#endif /* MANAGER_HPP_ */
