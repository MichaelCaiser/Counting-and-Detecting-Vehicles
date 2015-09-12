/**
 * @file		SecurityConstants.hpp
 * @version 	1.0
 * @author		Alonso Loaiza Pereira
 * @e-mail		aloaizapereira@gmail.com
 * @university 	Tecnológico de Costa Rica (TEC)
 *
 * @description
 * 		This file contains a simply declaration of constants which are required
 * 		by the security's namespace.
 */

#ifndef SECURITYCONSTANTS_HPP_
#define SECURITYCONSTANTS_HPP_

//Libraries
#include <string>	//Object String

/**
 * Date format where:
 * 		1. %m means month (1-12)
 * 		2. %d means day (1-31)
 * 		3. %Y means year (2015)
 * 		4. %H means hour (0-23)
 * 		5. %M means minutes (0-59)
 * 		6. %S means seconds (0-59)
 * 	Example: 12-01-1992 20:04:55
 */
static const std::string DATE_FORMAT = "%m-%d-%Y %H:%M:%S";

/* Key to encrypt the information by the XOR algorithm */
static const std::string TOKEN_KEY   = "xA123kJ%4z#@";

#endif /* SECURITYCONSTANTS_HPP_ */
