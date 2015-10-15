/*
 * @file 		JsonBuilder.hpp
 * @version		1.0
 * @author		Alonso Loaiza Pereira
 * @e-mail		aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 *
 * @description
 * 		This class permits the convertion of objects to the JSON (Java Script Object Notation) format. Specifically this class
 * 		allows the conversion of report objects, weather condition objects and vehicle record objects to the json format.<p>
 */

#ifndef JSONBUILDER_HPP_
#define JSONBUILDER_HPP_

//Libraries
#include <string>	/* String class defined in the std */
#include <vector>	/* Vector class defined in the std */
#include <sstream>  /* ostringstream class defined in the std */
#include <ctime>	/* time_t */
#include "Report.hpp"			/* Report class defined in the model namespace */
#include "WeatherCondition.hpp"	/* Weather condition class defined in the model namespace */
#include "VehicleRecord.hpp"	/* VehicleRecord class defined in the model namespace */

//Specification by namespace
using std::string;
using std::vector;
using std::ostringstream;
using Model::Report;
using Model::VehicleRecord;
using Model::WeatherCondition;

namespace WebService
{
	class JsonBuilder {
	public:
		//Constructor and destructor
		JsonBuilder();
		virtual ~JsonBuilder();

		//Methods
		string convertToJSON(Report &rReport);
		string convertToJSON(const VehicleRecord &rVehicleRecord);
		string convertToJSON(const WeatherCondition &rWeather);

	private:
		//Attributes
		ostringstream mStringBuffer;		/* Conversion from Int to String, from char[] to string */

		//Methods
		string convertString(const string &rString);
		string convertFloat(const float &rFloat);
		string convertInt(const int &rInt);
		string convertDate(const time_t &rDate);
		string convertArray(vector<string> rList);
	};

} /* namespace WebService */

#endif /* JSONBUILDER_HPP_ */
