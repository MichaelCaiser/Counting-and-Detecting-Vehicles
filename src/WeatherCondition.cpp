/*
 * @file 		WeatherCondition.cpp
 * @version 	1.0
 * @author 		Alonso Loaiza Pereira
 * @e-mail		aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 */

#include "WeatherCondition.hpp"

namespace Model {

/*
 *********************************************************************************
 *                           Constructor and Destructor                          *
 *********************************************************************************
 */
WeatherCondition::WeatherCondition(){
	mBrightness = 0;
	mHumidity = 0;
	mTemperature = 0;
}

WeatherCondition::WeatherCondition(float rBrightness, float rHumidity, float rTemperature) {
	mBrightness = rBrightness;
	mHumidity   = rHumidity;
	mTemperature = rTemperature;
}

WeatherCondition::~WeatherCondition() {
	// TODO Auto-generated destructor stub
}

/*
 *********************************************************************************
 *                           		GETTERS                                      *
 *********************************************************************************
 */
float WeatherCondition::getBrightness() const{
	return mBrightness;
}

float WeatherCondition::getHumidity() const{
	return mHumidity;
}

float WeatherCondition::getTemperature() const{
	return mTemperature;
}

/*
 *********************************************************************************
 *                           		SETTERS                                      *
 *********************************************************************************
 */
void WeatherCondition::setBrightness(float rValue){
	mBrightness = rValue;
}

void WeatherCondition::setHumidity(float rValue){
	mHumidity = rValue;
}

void WeatherCondition::setTemperature(float rValue){
	mTemperature = rValue;
}

} /* namespace Model */
