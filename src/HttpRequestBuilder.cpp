/**
 * @file		HttpRequestBuilder.cpp
 * @version		1.0
 * @author		Alonso Loaiza Pereira
 * @e-mail		aloaizapereira@gmail.com
 * @university	Tecnologico de Costa Rica (TEC)
 */

#include "HttpRequestBuilder.hpp"

//Libraries
#include "HttpConstants.hpp"	/* Header file with constants */
#include <sstream>				/* ostringstream object defined in the std */


//Specification by namespace
using std::ostringstream;

namespace WebService {


/*
 *********************************************************************************
 *                           Constructor and Destructor                          *
 *********************************************************************************
 */

HttpRequestBuilder::HttpRequestBuilder() {
	//Constructor
}

HttpRequestBuilder::~HttpRequestBuilder() {
	//Destructor
}

/*
 *********************************************************************************
 *                           		METHODS                                      *
 *********************************************************************************
 */


/**
 * This method creates a http request addressed to a web service by a specific host, port, url and a bdoy.
 * This http request is created as a post request. <p>
 *
 * @param 	rHost	The host which the request will be sent
 * @param 	rPort	The number of the port
 * @param	rUrl	The url to make the request
 * @param 	rBody	The body of the request
 * @return	string	A string with the format of a http response
 */
string HttpRequestBuilder::createHttpPostRequest(string rHost, int rPort, string rUrl, string rBody) {
	string http_request;

	//Http structure
	string http_header;
	string http_body = rBody;

	/* body lenght in bytes (a character has a size of one byte) */
	int body_length = http_body.size();

	/*
	 * Adds the resource, for example
	 * POST http://localhost:8080/RestExample/addEmployee HTTP/1.1
	 */
	http_header += METHOD_POST + HTTP_SPACE + rUrl + HTTP_SPACE + HTTP_VERSION;
	http_header += HTTP_NEW_LINE;

	//Adds the host, for example 'Host: localhost:8080'
	http_header += HOST_HEADER+ rHost + HEADER_VALUE_SEPAR + convertToString(rPort);
	http_header += HTTP_NEW_LINE;

	//Adds the content type header, In this case it is 'Content-Type: application/json; charset=utf-8'
	http_header += CONTENT_TYPE_HEADER;
	http_header += HTTP_NEW_LINE;

	//Adds the content lenght, for example 'Content-Length: 166'
	http_header += CONTENT_LENGTH_HEADER + convertToString(body_length);
	http_header += HTTP_NEW_LINE;

	//Joins the parts of the http request
	http_request += http_header;
	http_request += HTTP_NEW_LINE;
	http_request += http_body;

	return http_request;
}


/**
 * This method converts an integer to a string. <p>
 *
 * @param	rInt	An Integer
 * @return	string	A string that contains the integer
 */
string HttpRequestBuilder::convertToString(int rInt) {
	ostringstream string_buffer;
	string_buffer << rInt;
	string result = string_buffer.str();

	return result;
}

} /* namespace WebService */
