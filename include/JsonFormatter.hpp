/**
 * @file	JsonFormatter.hpp
 * @version	1.0
 * @author	Alonso Loaiza Pereira
 * @e-mail	aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 *
 * @description
 * 		This class defines the methods to create JSON (Java Script Notation Objects) attributes. This class cannot
 * 		be initialized (Abstract class), all the classes that want to implement a specific json class transformation
 * 		need to inherit for this class. <p>
 */

#ifndef JSONFORMATTER_HPP_
#define JSONFORMATTER_HPP_

//Libraries
#include <string>	/* String class defined in the std */
#include <vector>	/* Vector class defined in the std */

//Specification by namespace
using std::string;
using std::vector;

namespace JSON
{
	class JsonFormatter {
	public:
		//Destructor
		virtual ~JsonFormatter();

	protected:
		//Constructor
		JsonFormatter();

		//Methods
		string convertString(const string &rString);
		string convertFloat(const float &rFloat);
		string convertInt(const int &rInt);
		string convertDate(const time_t &rDate);
		string convertArray(vector<string> rList);
	};

} /* namespace JSON */

#endif /* JSONFORMATTER_HPP_ */
