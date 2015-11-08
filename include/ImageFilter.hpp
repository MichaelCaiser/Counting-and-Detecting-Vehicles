/**
 * @file	ImageFilter.hpp
 * @version	1.0
 * @author	Alonso Loaiza Pereira
 * @e-mail	aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 *
 * @description:
 * 		This class allows filter and image to prepared the image to the process of image analysis (extraction of
 * 		structures or information from an image). <p>
 */

#ifndef IMAGEFILTER_HPP_
#define IMAGEFILTER_HPP_

//Libraries
#include <opencv2/imgproc/imgproc.hpp>	/* Mat class and functions canny, blur, etc */

//Specification by Namespace
using cv::Mat;
using cv::Rect;

namespace ImageProcessing
{
	class ImageFilter {
	public:
		//Constructor and Destructor
		ImageFilter();
		virtual ~ImageFilter();

		//Setters
		void setROI(Rect* prRoi);

		//Methods
		Mat filter(const Mat &rImage);
	private:
		//Attributes
		Rect* pmROI;	/* Region of Interest */
	};

} /* namespace ImageProcessing */

#endif /* IMAGEFILTER_HPP_ */
