/**
 * @file	ConnectionConfig.cpp
 * @version	1.0
 * @author	Alonso Loaiza Pereira
 * @e-mail	aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 */

#include "ConnectionConfig.hpp"

namespace WebService {

/*
 *********************************************************************************
 *                           Constructor and Destructor                          *
 *********************************************************************************
 */

ConnectionConfig::ConnectionConfig(int rPort=0, string rHost="", string rUrl="") {
	mPort = rPort;
	mHost = rHost;
	mUrl = rUrl;
}

ConnectionConfig::~ConnectionConfig() {
	// TODO Auto-generated destructor stub
}

/*
 *********************************************************************************
 *                           		GETTERS                                      *
 *********************************************************************************
 */

int ConnectionConfig::getPort() const{
	return mPort;
}

string ConnectionConfig::getHost() const{
	return mHost;
}

string ConnectionConfig::getUrl() const{
	return mUrl;
}

/*
 *********************************************************************************
 *                           		SETTERS                                      *
 *********************************************************************************
 */

void ConnectionConfig::setPort(int rPort){
	mPort = rPort;
}

void ConnectionConfig::setHost(string rHost){
	mHost = rHost;
}

void ConnectionConfig::setUrl(string rUrl){
	mUrl = rUrl;
}

} /* namespace WebService */
