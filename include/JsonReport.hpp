/**
 * @file		JsonReport.hpp
 * @version		1.0
 * @author		Alonso Loaiza Pereira
 * @e-mail		aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 *
 * @description:
 * 		This class permits the conversion of report objects (defined in the namespace Model)
 * 		to the JSON (Java Script Object Notation) format.<p>
 */

#ifndef JSONREPORT_HPP_
#define JSONREPORT_HPP_

//Libraries
#include <string>		/* String class defined in the std */
#include "JsonFormatter.hpp"	/* JsonFormmater class defined in the namespace JSON */
#include "Report.hpp"			/* report class defined in the namespace Model */

//Specififaction by namespace
using std::string;
using JSON::JsonFormatter;
using Model::Report;

namespace JSON
{
	class JsonReport : public JsonFormatter {
	public:
		//Constructor and Destructor
		JsonReport();
		virtual ~JsonReport();

		//Methods
		string convertToJSON(const Report &rReport);
	};

} /* namespace JSON */

#endif /* JSONREPORT_HPP_ */
