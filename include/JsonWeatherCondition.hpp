/**
 * @file		JsonWeatherCondition.hpp
 * @version		1.0
 * @author		Alonso Loaiza Pereira
 * @e-mail		aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 *
 * @description:
 * 		This class permits the conversion of weather condition objects (defined in the namespace Model)
 * 		to the JSON (Java Script Object Notation) format.<p>
 */

#ifndef JSONWEATHERCONDITION_HPP_
#define JSONWEATHERCONDITION_HPP_

//Libraries
#include <string>				/* String class defined in the std */
#include "JsonFormatter.hpp"	/* JsonFormatter class defined in the namespace JSON */
#include "WeatherCondition.hpp"	/* WeatherCondition class defined in the namespace Model*/

//Specification by namespace
using std::string;
using JSON::JsonFormatter;
using Model::WeatherCondition;


namespace JSON
{
	class JsonWeatherCondition : public JsonFormatter {
	public:
		//Constructor and Destructor
		JsonWeatherCondition();
		virtual ~JsonWeatherCondition();

		//Methods
		string convertToJSON(const WeatherCondition &rWeather);
	};

} /* namespace JSON */

#endif /* JSONWEATHERCONDITION_HPP_ */
