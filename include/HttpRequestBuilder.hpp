/**
 * @file	HttpRequestBuilder.hpp
 * @version	1.0
 * @author	Alonso Loaiza Pereira
 * @e-mail	aloaizapereira@gmail.com
 * @university	Tecnologico de Costa Rica (TEC)
 *
 * @description
 * 		This class builds http requests with some data (port, host, url and request body), this request is necessary to send
 * 		the information to the web service. Also this class allows the verification if a http response is OK. <p>
 */

#ifndef HTTPREQUESTBUILDER_HPP_
#define HTTPREQUESTBUILDER_HPP_

//Libraries
#include <string>	/* string object defined in the std */

//Specification by namespace
using std::string;

namespace WebService
{
	class HttpRequestBuilder {
	public:
		//Constructor and Destructor
		HttpRequestBuilder();
		virtual ~HttpRequestBuilder();

		//Methods
		string createHttpPostRequest(string rHost, int rPort, string rUrl, string rBody);

	private:
		//Methods
		string convertToString(int rInt);
	};

} /* namespace WebService */

#endif /* HTTPREQUESTBUILDER_HPP_ */
