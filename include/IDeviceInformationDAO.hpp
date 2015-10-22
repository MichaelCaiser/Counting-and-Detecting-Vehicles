/*
 * @file 		IDeviceInformationDAO.hpp
 * @version 	1.0
 * @author  	Alonso Loaiza Pereira
 * @e-mail  	aloaizapereira@gmail.com
 * @university 	Tecnológico de Costa Rica(TEC)
 *
 * @description
 * 		This interface defines the methods for accessing the device's information (in this case
 * 		the device information correspond only to the device code which is the identifier of
 * 		the device which is used by the web server to differentiate between the devices). The
 * 		device code is a unique alphanumeric string with a length of 12 characters.
 */

#ifndef IDEVICEINFORMATIONDAO_HPP_
#define IDEVICEINFORMATIONDAO_HPP_

//Libraries
#include <string>	/* String object defined in the STD */

//Specification of classes by namespace
using std::string;

namespace DAO
{
	class IDeviceInformationDAO{
	public:
		//Destructor
		virtual ~IDeviceInformationDAO(){};

		//Abstract Methods

		/**
		 * This method return a pointer to a string object defined in the STD, this string contains the device code
		 * that is the code used to the application to be identified by the server. This code has a length of 12
		 * alphanumeric characters. <p>
		 */
		virtual string* getDeviceCode()=0;
	};

} /* namespace DAO */



#endif /* IDEVICEINFORMATIONDAO_HPP_ */
