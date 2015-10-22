/**
 * @file	HttpConstants.hpp
 * @version	1.0
 * @author	Alonso Loaiza Pereira
 * @e-mail	aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 *
 * @description
 * 		This header file only contains constants for the class HttpRequestBuilder. This constants are used
 * 		to create a Http Request to the web service to store the reports. If you want to know more about
 * 		the http protocol please visit this web site: http://www.w3.org/Protocols/rfc2616/rfc2616.html.<p>
 */

#ifndef HTTPCONSTANTS_HPP_
#define HTTPCONSTANTS_HPP_

//Libraries
#include <string>

/*
 *******************************************************************************
 *							HTTP Methods Types
 *******************************************************************************
 */

/* Declaration of a http post method */
const std::string METHOD_POST = "POST";

/* Declaration of a http get method*/
const std::string METHOD_GET = "GET";

/*
 *******************************************************************************
 *							HTTP Format Constants
 *******************************************************************************
 */

/* Declaration of the http request version */
const std::string HTTP_VERSION = "HTTP/1.1";

/* Http space */
const std::string HTTP_SPACE = " ";

/* Http new line */
const std::string HTTP_NEW_LINE = "\r\n";


/*
 *******************************************************************************
 *							HTTP Request Header Constants
 *******************************************************************************
 */

/* Declaration of the Header and value separator in a http request */
const std::string HEADER_VALUE_SEPAR = ":";

/* Declaration of the http host header in a http request */
const std::string HOST_HEADER = "Host: ";

/* Declaration of the http content type header */
const std::string CONTENT_TYPE_HEADER = "Content-Type: application/json; charset=utf-8";

/* Declaration of the http content lenght header */
const std::string CONTENT_LENGTH_HEADER = "Content-Length: ";

/*
 *******************************************************************************
 *							HTTP Response Constants
 *******************************************************************************
 */

/* Http header of a OK response */
const std::string HTTP_RESPONSE_OK = "HTTP/1.1 200 OK";

#endif /* HTTPCONSTANTS_HPP_ */
