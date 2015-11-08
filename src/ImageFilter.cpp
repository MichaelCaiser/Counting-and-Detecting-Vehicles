/**
 * @file	ImageFilter.cpp
 * @version	1.0
 * @author	Alonso Loaiza Pereira
 * @e-mail	aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 */

#include "ImageFilter.hpp"
using cv::Size;

namespace ImageProcessing {

/*
 *********************************************************************************
 *                           Constructor and Destructor                          *
 *********************************************************************************
 */
ImageFilter::ImageFilter() {
	// Constructor
	pmROI = NULL;
}

ImageFilter::~ImageFilter() {
	// Destructor
	delete pmROI;
}

/*
 *********************************************************************************
 *                           		SETTERS                                      *
 *********************************************************************************
 */

void ImageFilter::setROI(Rect* prRoi) {
	pmROI = prRoi;
}

/**
 * This method filter a Image (rImage) with different filters as gray scale, blur and canny, and also return a new image
 * that contains the original image filtered. <p>
 *
 * @param 	rImage	The image which will be filtered
 * @return	Mat	 	The original image but filtered
 */
Mat ImageFilter::filter(const Mat &rImage) {
	Mat filtered_image;
	//Applies the region of interest (ROI)
	filtered_image = rImage(*pmROI);
	//Converts the image to gray scale
	cvtColor(filtered_image, filtered_image, CV_BGR2GRAY);
	//Applies a blur filter with a kernel of 3
	blur(filtered_image, filtered_image, Size(3,3));
	//Applies the canny algorithm (with a threshold of 70-130) to the image to determined contours
	Canny(filtered_image, filtered_image, 70, 180, 3, true);
	return filtered_image;
}

} /* namespace ImageProcessing */
