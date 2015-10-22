//============================================================================
// Name        : main.cpp
// Author      : Alonso Loaiza Pereira
// Version     : 0.0 test mode
// Copyright   : MIT License
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// IMPORTANT NOTE
// At the moment I am learning about CppTest until I do it the tests cases will
// be in these part, I know that is a terrible way to do that but it's only for a
// moment.
//============================================================================

#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "TokenBuilder.hpp"
#include "TcpClient.hpp"
#include "FileReader.hpp"
#include "JsonReport.hpp"
#include "JsonVehicleRecord.hpp"
#include "JsonWeatherCondition.hpp"
#include "HttpRequestBuilder.hpp"
#include "Report.hpp"
#include "VehicleRecord.hpp"
#include "WeatherCondition.hpp"

using namespace std;
using Security::TokenBuilder;
using TCP_IP::TcpClient;
using TextParser::FileReader;
using JSON::JsonReport;
using JSON::JsonWeatherCondition;
using JSON::JsonVehicleRecord;
using HTTP::HttpRequestBuilder;
using Model::Report;
using Model::VehicleRecord;
using Model::WeatherCondition;

int main() {

	/*
	 ************************************************************************************
	 *								TEST 1.0 = Token generation
	 ************************************************************************************
     */
//	TokenBuilder* token_builder = new TokenBuilder();
//	token_builder->setEncryptionKey("comidacomida");
//	cout<< "Generated token: "<<token_builder->createToken()<<endl;
//
//	//Free memory
//	delete token_builder;

	/*
	 ************************************************************************************
	 *								TEST 2.0 = TcpClient
	 ************************************************************************************
     */
//	TcpClient* tcp_client = new TcpClient();
//	string host = "74.125.129.147"; 		//It's one of the ips of www.google.com one
//	string request = "Get / HTTP/1.1\r\n";	//Request to be sent
//	string response;
//	bool is_connected;
//	bool is_msg_sent;
//	bool is_msg_recv;
//	//try to connect to www.google.com, one ip of it is 74.125.129.147
//	is_connected = tcp_client->connect(host,80);
//	if(!is_connected){
//		return EXIT_FAILURE;
//	}
//	tcp_client->setNonBlocking(true);
//	cout<< "connection successfully to www.google.com" << endl;
//	is_msg_sent = tcp_client->send(request);
//	if(!is_msg_sent){
//		return EXIT_FAILURE;
//	}
//	cout<< "The message had being sent successfully to the host" << endl;
//	is_msg_recv = tcp_client->recv(response);
//	if(!is_msg_recv){
//		return EXIT_FAILURE;
//	}
//	cout<< "message received = " << response << endl;
//	tcp_client->closeConnection();
//	//free memory
//	delete tcp_client;

	/*
	 ************************************************************************************
	 *								TEST 3.0 = FileReader
	 ************************************************************************************
     */
//	FileReader* reader = new FileReader();
//
//	//Test load ROI
//	Rect* p_roi = reader->getROI();
//	cout << "Printing ROI" << endl;
//	cout << "Roi point: " << "( " << p_roi->x << ", " << p_roi ->y << " )" << endl;
//	cout << "Roi height: " << p_roi->height << endl;
//	cout << "Roi width:  " << p_roi->width  << endl;
//
//	cout << "" << endl;
//
//	//Test load Right Line
//	Line* p_right_line = reader->getRightLine();
//	cout << "Pringint Right Line" << endl;
//	cout << "Right Line gradient: " << p_right_line->getGradient() << endl;
//	cout << "Right Line Y Intercept: " << p_right_line->getYIntercept() << endl;
//
//
//	cout << "" << endl;
//
//	//Test load Left Line
//	Line* p_left_line = reader->getLeftLine();
//	cout << "Printing Left Line" << endl;
//	cout << "Left Line gradient: " << p_left_line->getGradient() << endl;
//	cout << "Left Line Y Intercept: " << p_left_line->getYIntercept() << endl;
//
//	cout << "" << endl;
//
//	//Test load device code
//	string* p_dev_code = reader->getDeviceCode();
//	cout << "Printing Device Code" << endl;
//	cout << "code: " << *p_dev_code << endl;
//
//	cout << "" << endl;
//
//	//Test load ConnectionConfig
//	ConnectionConfig* p_con_config = reader->getWebserviceConfig();
//	cout << "Printing Connection Configuration" << endl;
//	cout << "Port: " << p_con_config->getPort() << endl;
//	cout << "Host: " << p_con_config->getHost() << endl;
//	cout << "Url : " << p_con_config->getUrl()  << endl;
//
//
//	//free memory
//	delete p_roi;
//	delete p_right_line;
//	delete p_left_line;
//	delete p_dev_code;
//	delete p_con_config;
//	delete reader;

	/*
	 ************************************************************************************
	 *								TEST 4.0 = JsonBuilder
	 ************************************************************************************
     */
	JsonReport* p_json_report = new JsonReport();
	JsonWeatherCondition* p_json_weather = new JsonWeatherCondition();
	JsonVehicleRecord* p_json_vehicle = new JsonVehicleRecord();

	//Data for test
	Report* p_report = new Report();
	WeatherCondition* p_weather = new WeatherCondition();
	VehicleRecord* p_vehicle_one = new VehicleRecord();
	VehicleRecord* p_vehicle_two = new VehicleRecord();

	//weather condition initialization
	p_weather->setBrightness(56.0);
	p_weather->setHumidity(15.898);
	p_weather->setTemperature(12.0);


	//vehicle one initialization
	p_vehicle_one->setDate(time(0));
	p_vehicle_one->setSpeed(45.0);
	p_vehicle_one->setVehicleType("Light");
	p_vehicle_one->setLicensePlate("101110111");

	//vehicle two initialization
	p_vehicle_two->setDate(time(0));
	p_vehicle_two->setSpeed(15.0);
	p_vehicle_two->setVehicleType("Heavy");
	p_vehicle_two->setLicensePlate("202220222");

	//report initialization
	p_report->setDeviceCode("ABC123");
	p_report->setInitialDate(time(0));
	p_report->setFinalDate(time(0));
	p_report->setSecurityToken("XXXXXXX");
	p_report->setWeatherCondition(*p_weather);
	p_report->addRecord(p_vehicle_one);
	p_report->addRecord(p_vehicle_two);

	//Initial Headers
	cout << "Json TEST" << endl;

	//Test Json conversion of weather
	string json_weather = p_json_weather->convertToJSON(*p_weather);
	cout << "Test 1: WeatherCondition" << endl;
	cout << json_weather << endl;
	cout << "" << endl;

	//Test Json conversion of vehicle record
	string json_vehicle_record = p_json_vehicle->convertToJSON(*p_vehicle_one);
	cout << "Test 2: VehicleRecord" << endl;
	cout << json_vehicle_record << endl;
	cout << "" << endl;

	//Test Json conversion of report
	string json_report = p_json_report->convertToJSON(*p_report);
	cout << "Test 3: Report" << endl;
	cout << json_report << endl;
	cout << "" << endl;

	//free memory
	delete p_weather;
	delete p_report;
	delete p_json_report;
	delete p_json_weather;
	delete p_json_vehicle;

	/*
	 ************************************************************************************
	 *							TEST 5.0 = HttpRequestBuilder
	 ************************************************************************************
     */
//	HttpRequestBuilder* p_http_builder = new HttpRequestBuilder();
//	string host = "localhost";
//	int	port = 8080;
//	string url = "http//localhost:8080/WebAppCar/service/rest/embedded/addReport";
//	string body = "THIS IS A TEST";
//
//	string request = p_http_builder->createHttpPostRequest(host,port,url,body);
//
//	cout << "Http Builder Test" << endl;
//	cout << request << endl;

	return EXIT_SUCCESS;
}
