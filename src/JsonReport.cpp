/**
 * @file		JsonReport.cpp
 * @version		1.0
 * @author		Alonso Loaiza Pereira
 * @e-mail		aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 */

#include "JsonReport.hpp"

//Libraries
#include "JsonVehicleRecord.hpp"	/* JsonVehicleRecord class defined in the namespace JSON */
#include "JsonWeatherCondition.hpp"	/* JsonWeatherCondition class defined in the namespace JSON */
#include "VehicleRecord.hpp"		/* VehicleRecord class defined in the namespace Model */
#include "WeatherCondition.hpp"		/* WeatherCondition class defined in the namespace Model */
#include "JsonConstants.hpp"		/* header file with constants */

//Specification by namespace
using JSON::JsonVehicleRecord;
using JSON::JsonWeatherCondition;
using Model::VehicleRecord;
using Model::WeatherCondition;

namespace JSON {


/*
 *********************************************************************************
 *                           Constructor and Destructor                          *
 *********************************************************************************
 */

JsonReport::JsonReport() {
	// Constructor

}

JsonReport::~JsonReport() {
	// Destructor
}

/*
 *********************************************************************************
 *                           		METHODS                                      *
 *********************************************************************************
 */

/**
 * This method converts a report object to the json format.<p>
 *
 * @param 	rReport		The report object to be converted to a json format
 * @return	string		A string which represents the report object in the json format
 */
string JsonReport::convertToJSON(const Report &rReport) {
	// String to represent the report object
	string json_obj_string;
	//Class to convert weather objects to json
	JsonVehicleRecord json_record_formatter;
	//Class to convert vehicle record objects to json
	JsonWeatherCondition json_weather_formatter;

	string json_device_code = convertString(rReport.getDeviceCode());
	string json_sec_token = convertString(rReport.getSecurityToken());
	string json_initial_date = convertDate(rReport.getInitialDate());
	string json_final_date = convertDate(rReport.getFinalDate());
	string json_weather_condition = json_weather_formatter.convertToJSON(rReport.getWeatherCondition());

	vector<string> records_json_list;
	vector<VehicleRecord*> report_records = rReport.getRecords();
	//Creates an array of string that represents the vehicle records in the json format
	for(unsigned int index = 0; index < report_records.size();index++){
		VehicleRecord* p_vehicle_record = report_records.at(index);
		string json_record = json_record_formatter.convertToJSON(*p_vehicle_record);
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


} /* namespace JSON */
