/*
 * ConnectionConfiguration.cpp
 *
 *  Created on: 27/5/2015
 *      Author: alonso
 */

#include "ConnectionConfiguration.hpp"

/*
 *********************************************************************************
 *                           Constructor y Destructor                            *
 *********************************************************************************
 */
ConnectionConfiguration::ConnectionConfiguration() {
	// TODO Auto-generated constructor stub
	//Constructor
	mPort = 8080;	//Default
}

ConnectionConfiguration::ConnectionConfiguration(int rPort, string rHost, string rUrl)
{
	mPort = rPort;
	mHost = rHost;
	mUrlPostReport = rUrl;
}

ConnectionConfiguration::~ConnectionConfiguration() {
	// TODO Auto-generated destructor stub
	// Destructor
}

/*
 *********************************************************************************
 *                                GETTERS                                        *
 *********************************************************************************
 */

int ConnectionConfiguration::getPort()
{
	return mPort;
}

string ConnectionConfiguration::getHost()
{
	return mHost;
}

string ConnectionConfiguration::getUrlPostReport()
{
	return mUrlPostReport;
}

/*
 *********************************************************************************
 *                                SETTERS                                        *
 *********************************************************************************
 */
void ConnectionConfiguration::setPort(int rPort)
{
	mPort = rPort;
}

void ConnectionConfiguration::setHost(string rHost)
{
	mHost = rHost;
}

void ConnectionConfiguration::setUrlPostReport(string rUrl)
{
	mUrlPostReport = rUrl;
}

