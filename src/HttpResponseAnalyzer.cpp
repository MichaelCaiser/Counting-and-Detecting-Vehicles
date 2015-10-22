/**
 * @file	HttpResponseAnalyzer.cpp
 * @version	1.0
 * @author	Alonso Loaiza Pereira
 * @e-mail	aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 */

#include "HttpResponseAnalyzer.hpp"

//Libraries
#include "HttpConstants.hpp"	/* Header file with constants */

namespace HTTP {


/*
 *********************************************************************************
 *                           Constructor and Destructor                          *
 *********************************************************************************
 */

HttpResponseAnalyzer::HttpResponseAnalyzer() {
	// TODO Auto-generated constructor stub

}

HttpResponseAnalyzer::~HttpResponseAnalyzer() {
	// TODO Auto-generated destructor stub
}

/*
 *********************************************************************************
 *                           		METHODS                                      *
 *********************************************************************************
 */

/**
 * This method analyzes a http response (rResponse) to find if it is a OK response.<p>
 *
 * @param	rResponse	The http response to analyze
 * @return 	bool		A boolean value to determined if the http response is the OK type
 */
bool HttpResponseAnalyzer::isHttpResponseOK(string rResponse) {
	//Try to find a http new line in the response
	int pos_sub_string = rResponse.find(HTTP_NEW_LINE);
	//Check if finds the http new line in the response
	if(pos_sub_string == -1) {
		return false;
	}
	//Gets the header of the http response
	string element = rResponse.substr(0,pos_sub_string);
	//Compares the header of the http response with the format of a HTTP OK RESPONSE
	if(element.compare(HTTP_RESPONSE_OK) == 0) {
		return true;
	}
	return false;
}

} /* namespace WebService */
