/*
 * @file		SecurityTokenBuilder.hpp
 * @version 	1.0
 * @author		Alonso Loaiza Pereira
 * @e-mail		aloaizapereira@gmail.com
 * @university 	Tecnológico de Costa Rica (TEC)
 */

//Libraries
#include "TokenBuilder.hpp"
#include "SecurityConstants.hpp"	/* Header file with constants */

namespace Security {

/*
 *********************************************************************************
 *                           Constructor and Destructor                          *
 *********************************************************************************
 */
TokenBuilder::TokenBuilder() {
	mEncryptionKey = TOKEN_KEY;	//Assigned the default key
}

TokenBuilder::~TokenBuilder(){}

/*
 *********************************************************************************
 *                           		SETTERS                                      *
 *********************************************************************************
 */

void TokenBuilder::setEncryptionKey(string rStringKey)
{
	mEncryptionKey = rStringKey;
}

/*
 *********************************************************************************
 *                           		METHODS                                      *
 *********************************************************************************
 */

/**
 * This method create a security token by getting the current date in a string format and then
 * encrypting the string by a XOR algorithm.<p>
 *
 * @return 	string	This string is a security token
 */
string TokenBuilder::createToken()
{
	string date = getCurrentDate();
	string encrypted_date = encryptString(date);
	return encrypted_date;
}

/**
 * This method encrypt a string with a XOR algorithm in which every string's character is encrypted
 * applying a XOR with a character of a key. This key must be the same of the decoder, if it isn't
 * the decoder can not decode the information.<p>
 *
 * @param 	rString 	String which will be encrypted
 * @return 	string  	Encrypted string by a XOR algorithm.
 */
string TokenBuilder::encryptString(string rString)
{
	for(unsigned int counter = 0; counter < rString.size();counter++)
	{
		char string_character = rString.at(counter);
		char key_character    = mEncryptionKey.at(counter%mEncryptionKey.size());
		//apply a xor between character of the string and character of the key
		char encrypted_character = string_character ^ key_character;
		//replace the encrypted character into the string for the current position
		rString.replace(rString.begin()+counter,rString.begin()+counter+1,1,encrypted_character);
	}
	return rString;
}

/**
 * This method generates a string with the current date in a specific format
 * (month-day-year hour-minute-second).<p>
 *
 * @return 	string	This string contains the current date in a specific format (see SecurityConstants.hpp)
 */
string TokenBuilder::getCurrentDate()
{
	//get current date
	time_t actual_time = time(0);

	//convert time to a struct tm which contains date information
	struct tm * timeinfo = localtime (&actual_time);

	//buffer to store de date in string format
	char buffer[80];

	//becomes time struct tm to a string date format
	strftime (buffer,80,DATE_FORMAT.c_str(),timeinfo);

	//free memory
	delete timeinfo;

	string string_date(buffer);
	return string_date;
}

} /* namespace Security */
