/**
 * @file	HttpResponseAnalyzer.hpp
 * @version	1.0
 * @author	Alonso Loaiza Pereira
 * @e-mail	aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 *
 * @description:
 * 		This class permits analyze http responses. Specifically allows to know if a http response
 * 		is the type OK.<p>
 */

#ifndef HTTPRESPONSEANALYZER_HPP_
#define HTTPRESPONSEANALYZER_HPP_

//Libraries
#include <string>

//Specification by namespace
using std::string;

namespace HTTP
{
	class HttpResponseAnalyzer {
	public:
		//Constructor and Destructor
		HttpResponseAnalyzer();
		virtual ~HttpResponseAnalyzer();

		//Methods
		bool isHttpResponseOK(string rResponse);
	};

} /* namespace WebService */

#endif /* HTTPRESPONSEANALYZER_HPP_ */
