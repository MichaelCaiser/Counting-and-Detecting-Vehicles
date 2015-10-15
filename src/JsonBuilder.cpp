/*
 * @file		JsonBuilder.cpp
 * @version		1.0
 * @author		Alonso Loaiza Pereira
 * @e-mail		aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 */

#include "JsonBuilder.hpp"

//Libraries
#include "JsonConstants.hpp"	/* header file with constants */

namespace WebService {


/*
 *********************************************************************************
 *                           Constructor and Destructor                          *
 *********************************************************************************
 */

JsonBuilder::JsonBuilder() {
	//Constructor
}

JsonBuilder::~JsonBuilder() {
	//Destructor
}


/*
 *********************************************************************************
 *                           		METHODS                                      *
 *********************************************************************************
 */

string JsonBuilder::convertToJSON(Report &rReport){
	// String to represent the report object
	string json_obj_string;

	string json_device_code = convertString(rReport.getDeviceCode());
	string json_sec_token = convertString(rReport.getSecurityToken());
	string json_initial_date = convertDate(rReport.getInitialDate());
	string json_final_date = convertDate(rReport.getFinalDate());
	string json_weather_condition = convertToJSON(rReport.getWeatherCondition());

	vector<string> records_json_list;
	vector<VehicleRecord*> report_records = rReport.getRecords();
	//Creates an array of string that represents the vehicle records in the json format
	for(unsigned int index = 0; index < report_records.size();index++){
		VehicleRecord* p_vehicle_record = report_records.at(index);
		string json_record = convertToJSON(*p_vehicle_record);
		records_json_list.push_back(json_record);
	}
	//Creates a json list with the vector of strings
	string json_records = convertArray(records_json_list);

	//Adds the initial character of a json object
	json_obj_string += OBJ_START_CHAR;
	//Adds the device code attribute
	json_obj_string += REPORT_CODE_ATTR + ATTR_DECLA_CHAR + json_device_code;
	//Adds the separator character between attributes
	json_obj_string += ATTR_SEPAR_CHAR;
	//Adds the security token attribute
	json_obj_string += REPORT_TOKEN_ATTR + ATTR_DECLA_CHAR + json_sec_token;
	//Adds the separator character between attributes
	json_obj_string += ATTR_SEPAR_CHAR;
	//Adds the initial date attribute
	json_obj_string += REPORT_INIDATE_ATTR + ATTR_DECLA_CHAR + json_initial_date;
	//Adds the separator character between attributes
	json_obj_string += ATTR_SEPAR_CHAR;
	//Adds the final date attribute
	json_obj_string += REPORT_FINDATE_ATTR + ATTR_DECLA_CHAR + json_final_date;
	//Adds the separator character between attributes
	json_obj_string += ATTR_SEPAR_CHAR;
	//Adds the weather condition attribute
	json_obj_string += REPORT_WEATHER_ATTR + ATTR_DECLA_CHAR + json_weather_condition;
	//Adds the separator character between attributes
	json_obj_string += ATTR_SEPAR_CHAR;
	//Adds the records attribute
	json_obj_string += REPORT_RECORDS_ATTR + ATTR_DECLA_CHAR + json_records;
	//Adds the end character of a json object
	json_obj_string += OBJ_END_CHAR;

	return json_obj_string;
}

/**
 * This method converts a vehicle record object to the json format.<p>
 *
 * @param 	rVehicleRecord	The vehicle record object to be converted to the json format
 * @return 	string			A string which represents the vehicle record object in the json format
 */
string JsonBuilder::convertToJSON(const VehicleRecord &rVehicleRecord){
	// String to represent the vehicle record object
	string json_obj_string;

	string json_license = convertString(rVehicleRecord.getLicensePlate());
	string json_type = convertString(rVehicleRecord.getVehicleType());
	string json_speed= convertFloat(rVehicleRecord.getSpeed());
	string json_date = convertDate(rVehicleRecord.getDate());

	//Adds the initial character of a json object
	json_obj_string += OBJ_START_CHAR;
	//Adds the license plate attribute
	json_obj_string += RECORD_LICEN_ATTR + ATTR_DECLA_CHAR + json_license;
	//Adds the separator character between attributes
	json_obj_string += ATTR_SEPAR_CHAR;
	//Adds the vehicle type attribute
	json_obj_string += RECORD_TYPE_ATTR + ATTR_DECLA_CHAR + json_type;
	//Adds the separator character between attributes
	json_obj_string += ATTR_SEPAR_CHAR;
	//Adds the speed attribute
	json_obj_string += RECORD_SPEED_ATTR + ATTR_DECLA_CHAR + json_speed;
	//Adds the separator character between attributes
	json_obj_string += ATTR_SEPAR_CHAR;
	//Adds the date attribute
	json_obj_string += RECORD_DATE_ATTR + ATTR_DECLA_CHAR + json_date;
	//Adds the end character of a json object
	json_obj_string += OBJ_END_CHAR;

	return json_obj_string;
}


/**
 * This method converts a weather condition object to the json format.<p>
 *
 * @param 	rWeather	The weather condition object to be converted to a json format
 * @return	string		A string which represents the weather condition object in the json format
 */
string JsonBuilder::convertToJSON(const WeatherCondition &rWeather){
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


/**
 * This method creates
 */
string JsonBuilder::convertArray(vector<string> rList){
	// String to represent the json list
	string json_list;
	int records_quantity = rList.size();

	//Adds the json list initial character
	json_list += LIST_START_CHAR;

	for(int index = 0; index < records_quantity; index++){
		string list_item = rList.at(index);
		json_list += list_item;
		//Check that don't be the last element in the vector
		if(index != records_quantity-1){
			//Adds the json list separator character
			json_list += LIST_SEPAR_CHAR;
		}
	}
	//Adds the json list end character
	json_list += LIST_END_CHAR;
	return json_list;
}

/**
 * This method converts a string in the json format. <p>
 *
 * @param 	rString 	A reference to a string which must be converted to the JSON format
 * @return 	string		A string that represents a string in JSON
 */
string JsonBuilder::convertString(const string &rString){
	string json_string = STRING_DECLA_CHAR+rString+STRING_DECLA_CHAR;
	return json_string;
}

/**
 * This method converts a float in a string with the json format of a float. <p>
 *
 * @param 	rFloat	A reference to a float which must be converted to the JSON format
 * @return 	string	A string that represents a float in JSON
 */
string JsonBuilder::convertFloat(const float &rFloat){
	//Clear the buffer
	mStringBuffer.str("");
	mStringBuffer.clear();

	mStringBuffer<<rFloat;
	string result = mStringBuffer.str();

	//Check if the string hasn't a point (A character like '.')
	if(result.find(FLOAT_POINT) == string::npos){
		//Add a point and cero to the string.
		result = result+FLOAT_CERO_END;
	}
	return result;
}

/**
 * This method converts a integer in a string with the json format of a Integer. <p>
 *
 * @param 	rInt	A reference to a integer which must be converted to the JSON format
 * @return 	string	A string that represents a intenger in JSON
 */
string JsonBuilder::convertInt(const int &rInt){
	//Clear the buffer
	mStringBuffer.str("");
	mStringBuffer.clear();

	mStringBuffer<<rInt;
	string result = mStringBuffer.str();
	return result;
}

/**
 * This method converts a date (time_t) in a string with the json format. The json format for date is as
 * follows: year-month-dayThour:minutes:seconds-TIMEZONE. <p>
 *
 * @param 	rDate	A time_t object that represents a date which must be converted to the json format
 * @return 	string	A string that represents a date in the json format
 */
string JsonBuilder::convertDate(const time_t &rDate){
	/* Buffer to store the date in a specific format */
	char buffer[30];
	/* Gives the format to the date */
	strftime(buffer,30,JSON_DATE_FORMAT.c_str(),localtime(&rDate));

	//Clear the buffer
	mStringBuffer.str("");
	mStringBuffer.clear();

	mStringBuffer<<buffer;
	string result = mStringBuffer.str();
	return result;
}

} /* namespace WebService */
