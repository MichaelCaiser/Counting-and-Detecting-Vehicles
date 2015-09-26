/*
 * @file		Line.hpp
 * @version 	1.0
 * @author		Alonso Loaiza Pereira
 * @e-mail		aloaizapereira@gmail.com
 * @university 	Tecnológico de Costa Rica (TEC)
 *
 * @description
 * 		This class is a description of a straight line equation(y = mx+b). This class can calculate images
 * 		and preimages of a straight line.
 */

#ifndef LINE_HPP_
#define LINE_HPP_

namespace DAO
{
	class Line {
	public:

		//Constructor and Destructor
		Line(float rPositionX1, float rPositionY1, float rPositionX2, float rPositionY2);
		virtual ~Line();

		//Getters
		float getGradient();
		float getYIntercept();

		//Methods
		float calculateImage(float rPreimage);
		float calculatePreimage(float rImage);

	private:

		//Attributes
		float mGradient;	/* Gradient of the line (m) */
		float mYIntercept; 	/* Intercept with Y axis (b) */
	};

} /* namespace Structure */

#endif /* LINE_HPP_ */
