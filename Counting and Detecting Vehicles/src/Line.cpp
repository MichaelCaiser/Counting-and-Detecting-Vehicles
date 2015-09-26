/*
 * @file		Line.hpp
 * @version 	1.0
 * @author		Alonso Loaiza Pereira
 * @e-mail		aloaizapereira@gmail.com
 * @university 	Tecnológico de Costa Rica (TEC)
 */

#include "Line.hpp"

namespace DAO {

/*
 *********************************************************************************
 *                           Constructor y Destructor                            *
 *********************************************************************************
 */

/**
 * This is a constructor method, the parameters of the method are two points which describes
 * the line. rPositionX1 and rPositionY1 are the first point, rPositionX1 and rPositionY2 are
 * the second point of the line.<p>
 *
 * @param rPositionX1	X position of the first point of the line
 * @param rPositionY1	Y position of the first point of the line
 * @param rPositionX2 	X position of the second point of the line
 * @param rPositionY2   Y position of the second point of the line
 */
Line::Line(float rPositionX1, float rPositionY1, float rPositionX2, float rPositionY2) {

	//Change in the X axis
	float x_change = rPositionX2-rPositionX1;
	//Change in the Y axis
	float y_change = rPositionY2-rPositionY1;

	mGradient = y_change/x_change;
	mYIntercept = rPositionY1-(mGradient*rPositionX1);
}

Line::~Line() {
	// TODO Auto-generated destructor stub
}

/*
 *********************************************************************************
 *                           		GETTERS                                      *
 *********************************************************************************
 */

float Line::getGradient(){
	return mGradient;
}

float Line::getYIntercept(){
	return mYIntercept;
}

/*
 *********************************************************************************
 *                           		METHODS                                      *
 *********************************************************************************
 */

/**
 * This method calculate the image of a specific preimage. The image of a straight line is
 * calculated as this equation: y=mx+b where y is the image and x the preimage.<p>
 *
 * @param rPreimage 	Preimage.
 * @return float 		The image of the preimage.
 */
float Line::calculateImage(float rPreimage){

	//y = mx + b
	float image = (rPreimage*mGradient) + mYIntercept;
	return image;
}

/**
 * This method calculate the preimage of a specific image. The preimage of a straight line is
 * calculated as this equation: x = (y - b)/m where y is the image and x the preimage.<p>
 *
 * @param rImage 	Image.
 * @return float 	The preimage of the image.
 */
float Line::calculatePreimage(float rImage){

	// x = (y - b)/m
	float preimage = (rImage - mYIntercept)/mGradient;
	return preimage;
}

} /* namespace Structure */
