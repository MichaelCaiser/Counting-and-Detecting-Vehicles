/**
 * @file	JsonFormatter.cpp
 * @version	1.0
 * @author	Alonso Loaiza Pereira
 * @e-mail	aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 */

#include "JsonFormatter.hpp"

//Libraries
#include <sstream>  			/* ostringstream class defined in the std */
#include "JsonConstants.hpp"	/* header file with constants */

//Specification by namespace
using std::ostringstream;

namespace JSON {

/*
 *********************************************************************************
 *                           Constructor and Destructor                          *
 *********************************************************************************
 */

JsonFormatter::JsonFormatter() {
	// Constructor

}

JsonFormatter::~JsonFormatter() {
	// Destructor
}


/*
 *********************************************************************************
 *                           		METHODS                                      *
 *********************************************************************************
 */

/**
 * This method converts a string in the json format. <p>
 *
 * @param 	rString 	A reference to a string which must be converted to the JSON format
 * @return 	string		A string that represents a string in JSON
 */
string JsonFormatter::convertString(const string &rString){
	string json_string = STRING_DECLA_CHAR+rString+STRING_DECLA_CHAR;
	return json_string;
}

/**
 * This method converts a float in a string with the json format of a float. <p>
 *
 * @param 	rFloat	A reference to a float which must be converted to the JSON format
 * @return 	string	A string that represents a float in JSON
 */
string JsonFormatter::convertFloat(const float &rFloat) {
	ostringstream string_buffer;
	string_buffer<<rFloat;
	string result = string_buffer.str();
	//Check if the string hasn't a point (A character like '.')
	if(result.find(FLOAT_POINT) == string::npos) {
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
string JsonFormatter::convertInt(const int &rInt) {
	ostringstream string_buffer;
	string_buffer << rInt;
	string result = string_buffer.str();
	return result;
}

/**
 * This method converts a date (time_t) in a string with the json format. The json format for date is as
 * follows: year-month-dayThour:minutes:seconds-TIMEZONE. <p>
 *
 * @param 	rDate	A time_t object that represents a date which must be converted to the json format
 * @return 	string	A string that represents a date in the json format
 */
string JsonFormatter::convertDate(const time_t &rDate) {
	/* Buffer to store the date in a specific format */
	char buffer[30];
	/* Gives the format to the date */
	strftime(buffer,30,JSON_DATE_FORMAT.c_str(),localtime(&rDate));

	ostringstream string_converter;
	string_converter << buffer;
	string result = string_converter.str();
	return result;
}

/**
 * This method creates a string that represents a list in the json format that list is building with
 * the elements of the string list (rList) which represent json objects. <p>
 *
 * @param 	rList	A list of strings that represents objects in JSON
 * @return	string	A string that represents a list of json objects
 */
string JsonFormatter::convertArray(vector<string> rList){
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

} /* namespace JSON */
