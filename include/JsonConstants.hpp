/*
 * @file 		JsonConstants.hpp
 * @version		1.0
 * @author		Alonso Loaiza Pereira
 * @e-mail		aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 *
 * @description
 * 		This header file only contains constants for the class JsonBuilder. This constants are used
 * 		to create the JSON (Java Script Object Notation) objects with the correct semantic. If you
 * 		want to know more about the json specification please visit this web site: http://www.json.org/.<p>
 */

#ifndef JSONCONSTANTS_HPP_
#define JSONCONSTANTS_HPP_

//Libraries
#include <string>	/* string object defined in the std */

/*
 *******************************************************************************
 *							JSON Object Constants
 *******************************************************************************
 */

/* Initial character to describe an object by JSON */
const std::string OBJ_START_CHAR = "{";

/* End character to describe an object by JSON */
const std::string OBJ_END_CHAR = "}";

/* Declaration of the date format in json */
const std::string JSON_DATE_FORMAT = "\"%Y-%m-%dT%T-0600\"";

/*
 *******************************************************************************
 *							JSON Attribute Constants
 *******************************************************************************
 */

/* Character to separate the value and the name of an attribute in a json object */
const std::string ATTR_DECLA_CHAR = ":";

/* Separator character for attributes in a json object*/
const std::string ATTR_SEPAR_CHAR  = ",";

/*
 *******************************************************************************
 *							JSON List Constants
 *******************************************************************************
 */

/* Initial character to describe a list in json */
const std::string LIST_START_CHAR = "[";

/* End character to describe a list in json */
const std::string LIST_END_CHAR = "]";

/* Separator character for items in a json list*/
const std::string LIST_SEPAR_CHAR = ",";

/*
 *******************************************************************************
 *							JSON Float Constants
 *******************************************************************************
 */

/*
 * Point for floats in json to separate decimals values
 * Example: 2.45, 356.67
 */
const std::string FLOAT_POINT    = ".";

/*
 * Final value for floats with whole values in json. Example if a float is 4 in json that float will be
 * represented as 4.0
 */
const std::string FLOAT_CERO_END = ".0";

/*
 *******************************************************************************
 *							JSON String Constants
 *******************************************************************************
 */

/* String declaration character in a json object, it must be in the beginning and the end of a string */
const std::string STRING_DECLA_CHAR    = "\"";

/*
 *******************************************************************************
 *						JSON Report Class Constants
 *******************************************************************************
 */

/* Declaration of the json identifier for a device code attribute in the report class */
const std::string REPORT_CODE_ATTR = "\"DeviceCode\"";

/* Declaration of the json identifier for an initial date attribute in the report class */
const std::string REPORT_INIDATE_ATTR = "\"InitialDate\"";

/* Declaration of the json identifier for a final date attribute in the report class */
const std::string REPORT_FINDATE_ATTR = "\"EndDate\"";

/* Declaration of the json identifier for a security token attribute in the report class */
const std::string REPORT_TOKEN_ATTR = "\"SecurityToken\"";

/* Declaration of the json identifier for a weather attribute in the report class */
const std::string REPORT_WEATHER_ATTR = "\"Weather\"";

/* Declaration of the json identifier for records attribute in the report class */
const std::string REPORT_RECORDS_ATTR = "\"Records\"";

/*
 *******************************************************************************
 *						JSON Vehicle Record Class Constants
 *******************************************************************************
 */

/* Declaration of the json identifier for the license plate attribute in the vehicle record class */
const std::string RECORD_LICEN_ATTR     = "\"LicensePlate\"";

/* Declaration of the json identifier for the vehicle type attribute in the vehicle record class */
const std::string RECORD_TYPE_ATTR      = "\"VehicleType\"";

/* Declaration of the json identifier for the speed attribute in the vehicle record class */
const std::string RECORD_SPEED_ATTR = "\"Speed\"";

/* Declaration of the json identifier for the date attribute in the vehicle record class */
const std::string RECORD_DATE_ATTR     = "\"Date\"";

/*
 *******************************************************************************
 *						JSON Weather Class Constants
 *******************************************************************************
 */

/* Declaration of the json identifier for the humidity attribute in the weather condition class */
const std::string WEATHER_HUM_ATTR = "\"Humidity\"";

/* Declaration of the json identifier for the temperature attribute in the weather condition class */
const std::string WEATHER_TEMP_ATTR = "\"Temperature\"";

/* Declaration of the json identifier for the brightness attribute in the weather condition class */
const std::string WEATHER_BRIGHT_ATTR = "\"Brightness\"";

#endif /* JSONCONSTANTS_HPP_ */
