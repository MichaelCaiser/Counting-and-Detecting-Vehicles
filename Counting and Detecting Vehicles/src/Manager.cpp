/*
 * Manager.cpp
 *
 *  Created on: 7/4/2015
 *      Author: alonso
 */

#include "Manager.hpp"

Manager::Manager()
{
	// TODO Auto-generated constructor stub
}

Manager::~Manager()
{
	// TODO Auto-generated destructor stub
}

int Manager::iniciarPrograma(int pIdCamara)
{
	_VideoCamara = new VideoCapture(pIdCamara);
	if(!_VideoCamara->isOpened())
	{
		return -1; //Error de conexion
	}

	namedWindow("stream",WINDOW_NORMAL);

	Mat image;
	while(true)
	{
		_VideoCamara->read(image);
		imshow("stream", image);
		int key = waitKey(33);
		if(key == 27)
		{
			break;
		}
	}
	_VideoCamara->release();
	return 0;
}


