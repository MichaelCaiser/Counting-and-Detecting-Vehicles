/*
 * @file 		IFilterConfigurationDAO.hpp
 * @version 	1.0
 * @Author  	Alonso Loaiza Pereira
 * @e-mail  	aloaizapereira@gmail.com
 * @university 	Tecnologico de Costa Rica (TEC)
 *
 * @description
 * 		Interface which function is give the information related with the configuration of image processing
 * 		to the application, specifically information related with the filter applied to images.
 * 		This interface defines get methods to obtain the Regions of Interest (ROI) and the street's
 * 		delimiters (RightLine and LeftLine).
 */

#ifndef IFILTERCONFIGURATIONDAO_HPP_
#define IFILTERCONFIGURATIONDAO_HPP_

//Libraries
#include <opencv2/imgproc/imgproc.hpp>	/* Object Rect of the lib opencv */
#include "Line.hpp"						/* Line object */

//Specification of classes by namespace
using cv::Rect;
using Model::Line;

namespace DAO
{
	class IFilterConfigurationDAO{
	public:

		//Destructor
		virtual ~IFilterConfigurationDAO(){};

		//Abstract Methods

		/**
		 * This method return a pointer to a Rectangle object defined in the opencv's namespace, this rectangle
		 * is called for this purpose region of interest (ROI) which corresponds a sector of the image that will
		 * be used to process the information and determine the vehicles which pass the road.<p>
		 */
		virtual Rect* getROI() = 0;

		/**
		 * This method return a pointer to a Line object which describes the right limit of the ROI.<p>
		 */
		virtual Line* getRightLine() = 0;

		/**
		 * This method return a pointer to a Line object which describes the left limit of the ROI.<p>
		 */
		virtual Line* getLeftLine() = 0;
	};

} /* namespace DAO */



#endif /* IFILTERCONFIGURATIONDAO_HPP_ */
