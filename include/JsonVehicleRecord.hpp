/**
 * @file		JsonVehicleRecord.hpp
 * @version		1.0
 * @author		Alonso Loaiza Pereira
 * @e-mail		aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 *
 * @description:
 * 		This class permits the conversion of vehicle record objects (defined in the namespace Model)
 * 		to the JSON (Java Script Object Notation) format.<p>
 */

#ifndef JSONVEHICLERECORD_HPP_
#define JSONVEHICLERECORD_HPP_

//Libraries
#include <string>				/* String class defined in the std */
#include "JsonFormatter.hpp"	/* JsonFormatter class defined in the namespace JSON */
#include "VehicleRecord.hpp"	/* VehicleRecord class defined in the namespace Model */


//Specification by namespace
using std::string;
using JSON::JsonFormatter;
using Model::VehicleRecord;

namespace JSON
{
	class JsonVehicleRecord : public JsonFormatter {
	public:
		//Constructor and Destructor
		JsonVehicleRecord();
		virtual ~JsonVehicleRecord();

		//Methods
		string convertToJSON(const VehicleRecord &rVehicleRecord);
	};

} /* namespace JSON */

#endif /* JSONVEHICLERECORD_HPP_ */
