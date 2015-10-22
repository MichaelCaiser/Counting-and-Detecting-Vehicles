/**
 * @file		JsonVehicleRecord.cpp
 * @version		1.0
 * @author		Alonso Loaiza Pereira
 * @e-mail		aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 */

#include "JsonVehicleRecord.hpp"

//Libraries
#include "JsonConstants.hpp"		/* header file with constants */

namespace JSON {

/*
 *********************************************************************************
 *                           Constructor and Destructor                          *
 *********************************************************************************
 */

JsonVehicleRecord::JsonVehicleRecord() {
	// TODO Auto-generated constructor stub

}

JsonVehicleRecord::~JsonVehicleRecord() {
	// TODO Auto-generated destructor stub
}

/*
 *********************************************************************************
 *                           		METHODS                                      *
 *********************************************************************************
 */


/**
 * This method converts a vehicle record object to the json format.<p>
 *
 * @param 	rVehicleRecord	The vehicle record object to be converted to the json format
 * @return 	string			A string which represents the vehicle record object in the json format
 */

string JsonVehicleRecord::convertToJSON(const VehicleRecord &rVehicleRecord) {
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

} /* namespace JSON */
