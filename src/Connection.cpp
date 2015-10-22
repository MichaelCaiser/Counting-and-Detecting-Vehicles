/**
 * @file	Connection.cpp
 * @version	1.0
 * @author	Alonso Loaiza Pereira
 * @e-mail	aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 */

#include "Connection.hpp"

//Libraris
#include <iostream>					/* cerr, endl */
#include <string>					/* string class defined in th std */
#include "TcpClient.hpp"			/* TcpClient class defined in the TCP_IP namespace */
#include "JsonReport.hpp"			/* JsonReport class defined in th JSON namespace */
#include "HttpRequestBuilder.hpp"	/* HttpRequestBuilder class defined in the namespace HTTP */
#include "HttpResponseAnalyzer.hpp"	/* HttpResponseAnalyzer class defined in the namespace HTTP */


//Specification by namespace
using std::cerr;
using std::endl;
using TCP_IP::TcpClient;
using JSON::JsonReport;
using HTTP::HttpRequestBuilder;
using HTTP::HttpResponseAnalyzer;


namespace WebService {


/*
 *********************************************************************************
 *                           Constructor and Destructor                          *
 *********************************************************************************
 */
Connection::Connection() {
	// Constructor
	pmConfiguration = NULL;
}

Connection::~Connection() {
	// Free memory
	delete pmConfiguration;
}

/*
 *********************************************************************************
 *                           		SETTERS                                      *
 *********************************************************************************
 */
void Connection::setConnectionConfig(ConnectionConfig* prConnectionConfig) {
	pmConfiguration = prConnectionConfig;
}

/*
 *********************************************************************************
 *                           		METHODS                                      *
 *********************************************************************************
 */

/**
 * This method sends a report object (rReport) by a TCP connection to the webservice to be stored.
 * If the report was sent successfully to the webservice this method doesn't print an error message
 * on the screen otherwise an error message will be showed on the screen. <p>
 *
 * @param	rReport		The report object that will be sent to the webservice
 */
void Connection::save(Report &rReport) {
	TcpClient tcp_client;
	JsonReport json_report_builder;
	HttpRequestBuilder http_request_builder;
	HttpResponseAnalyzer http_response_analyzer;

	//Service connection information

	string host = pmConfiguration->getHost();
	int port = pmConfiguration->getPort();
	string url = pmConfiguration->getUrl();

	//Checks if can established connection with the server by TCP
	if( !tcp_client.connect( host, port ) ) {
		cerr << "Error:  can't connect with the server" << endl;
		return;
	}

	//Creates the string that represents a report object in the JSON format
	string string_json_report = json_report_builder.convertToJSON(rReport);
	//Creates a http request with the string json report as the body
	string http_request = http_request_builder.createHttpPostRequest(host, port, url, string_json_report);
	string http_response;

	//Checks if the message (http request) could be sent successfully to the server
	if( !tcp_client.send( http_request ) ) {
		return;
	}

	//Checks if the server sent a response to the server
	if( !tcp_client.recv( http_response ) ) {
		return;
	}

	//Check if th http response sent by the server is the Ok type
	if( http_response_analyzer.isHttpResponseOK( http_response ) ) {
		cerr << "Error: the report couldn't be send successfully" << endl;
		return;
	}

	tcp_client.closeConnection();
}

} /* namespace WebService */
