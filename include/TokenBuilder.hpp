/**
 * @file		SecurityTokenBuilder.hpp
 * @version 	1.0
 * @author		Alonso Loaiza Pereira
 * @e-mail		aloaizapereira@gmail.com
 * @university 	Tecnológico de Costa Rica (TEC)
 *
 * @description
 * 		This class creates security tokens, this tokens are necessary because all the information
 * 		transmitted to the server will be checked, the token has a validity that depends of time
 * 		(normally is about 5 minutes).
 */

#ifndef TOKENBUILDER_HPP_
#define TOKENBUILDER_HPP_

//Libraries
#include <string>	/* Object string */
#include <time.h>	/* time_t, struct tm, localtime, strftime */

//Specification of classes by namespace
using std::string;

namespace Security
{
	class TokenBuilder {
	public:
		//Constructor and Destructor
		TokenBuilder();
		virtual ~TokenBuilder();

		//Setters
		void   setEncryptionKey(string rStringKey);

		//Methods
		string createToken();

	private:
		//Attributes
		string mEncryptionKey;	//The key to encrypt token's information

		//Methods
		string encryptString(string rString);
		string getCurrentDate();
	};

} /* namespace Security */

#endif /* TOKENBUILDER_HPP_ */
