/*
 * FilterManager.cpp
 *
 *  Created on: 7/4/2015
 *      Author: alonso
 */

#include "FilterManager.hpp"

FilterManager::FilterManager()
{
	// TODO Auto-generated constructor stub
}

FilterManager::~FilterManager()
{
	// TODO Auto-generated destructor stub
}

Mat* FilterManager::convertirEscalaGrises(Mat* rImagen)
{
	Mat* imagen_grises = new Mat();
	cvtColor(*rImagen, *imagen_grises, CV_BGR2GRAY);
	return imagen_grises;
}

