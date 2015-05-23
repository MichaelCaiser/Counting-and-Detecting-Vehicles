/*
 * FilterManager.hpp
 *
 *  Created on: 7/4/2015
 *      Author: alonso
 */

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

#ifndef FILTERMANAGER_HPP_
#define FILTERMANAGER_HPP_

class FilterManager {
public:
	FilterManager();
	virtual ~FilterManager();
	Mat* convertirEscalaGrises(Mat* rImagen);


};

#endif /* FILTERMANAGER_HPP_ */
