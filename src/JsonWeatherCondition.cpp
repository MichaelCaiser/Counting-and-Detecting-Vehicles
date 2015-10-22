/**
 * @file		JsonWeatherCondition.cpp
 * @version		1.0
 * @author		Alonso Loaiza Pereira
 * @e-mail		aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 */

#include "JsonWeatherCondition.hpp"

//Libraries
#include "JsonConstants.hpp"	/* header file with constants */

namespace JSON {

/*
 *********************************************************************************
 *                           Constructor and Destructor                          *
 *********************************************************************************
 */

JsonWeatherCondition::JsonWeatherCondition() {
	// Constructor

}

JsonWeatherCondition::~JsonWeatherCondition() {
	// Destructor
}

/*
 *********************************************************************************
 *                           		METHODS                                      *
 *********************************************************************************
 */

/**
 * This method converts a weather condition object to the json format.<p>
 *
 * @param 	rWeather	The weather condition object to be converted to a json format
 * @return	string		A string which represents the weather condition object in the json format
 */
string JsonWeatherCondition::convertToJSON(const WeatherCondition &rWeather) {
	// String to represent the weather object
	string json_obj_string;

	string json_humidity = convertFloat(rWeather.getHumidity());
	string json_temperature = convertFloat(rWeather.getTemperature());
	string json_brightness = convertFloat(rWeather.getBrightness());

	//Adds the initial character of a json object
	json_obj_string += OBJ_START_CHAR;
	//Adds the attribute humidity
	json_obj_string += WEATHER_HUM_ATTR + ATTR_DECLA_CHAR + json_humidity;
	//Adds the separator character between attributes
	json_obj_string += ATTR_SEPAR_CHAR;
	//Adds the attribute temperature
	json_obj_string += WEATHER_TEMP_ATTR + ATTR_DECLA_CHAR + json_temperature;
	//Adds the separator character between attributes
	json_obj_string += ATTR_SEPAR_CHAR;
	//Adds the attribute brightness
	json_obj_string += WEATHER_BRIGHT_ATTR + ATTR_DECLA_CHAR + json_brightness;
	//Adds the end character of a json object
	json_obj_string += OBJ_END_CHAR;

	return json_obj_string;
}

} /* namespace JSON */
