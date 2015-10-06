/*
 * @file 		WeatherCondition.hpp
 * @version 	1.0
 * @author 		Alonso Loaiza Pereira
 * @e-mail		aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 *
 * @description
 * 		This class is a simply representation of the weather condition in a place. The variables that represent the
 * 		weather are humidity, brightness and temperature.
 */

#ifndef WEATHERCONDITION_HPP_
#define WEATHERCONDITION_HPP_

namespace Model
{
	class WeatherCondition {
	public:
		//Constructor and Destructor
		WeatherCondition();
		WeatherCondition(float rBrightness, float rHumidity, float rTemperature);
		virtual ~WeatherCondition();

		//Getters
		float getBrightness() const;
		float getHumidity() const;
		float getTemperature() const;

		//Setters
		void setBrightness(float rValue);
		void setHumidity(float rValue);
		void setTemperature(float rValue);

	private:
		//Attributes
		float mBrightness;	//Brightness
		float mHumidity;	//Humidity
		float mTemperature; //Temperature
	};

} /* namespace Model */

#endif /* WEATHERCONDITION_HPP_ */
