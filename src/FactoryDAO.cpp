/*
 * @file	FactoryDAO.cpp
 * @version	1.0
 * @author	Alonso Loaiza Pereira
 * @e-mail	aloaizapereira@gmail.com
 * @universtity	Tecnológico de Costa Rica (TEC)
 */

#include "FactoryDAO.hpp"

//Libraries
#include "FileReader.hpp"	/* FileReader class defined in the TextParser namespace */
#include "Connection.hpp"	/* Connection class defined in the WebService namespace */
#include "ConnectionConfig.hpp"	/* ConnectionConfig class defined in the WebService namespace */

//Specification by namespace
using TextParser::FileReader;
using WebService::Connection;
using WebService::ConnectionConfig;

namespace Factory {


/*
 *********************************************************************************
 *                           Constructor and Destructor                          *
 *********************************************************************************
 */

FactoryDAO::FactoryDAO() {
	// Constructor
}

FactoryDAO::~FactoryDAO() {
	// Destructor
}

/*
 *********************************************************************************
 *                           		GETTERS                                      *
 *********************************************************************************
 */

/**
 * This method creates and file reader object that implements the IDeviceInformationDAO interface
 * and return a pointer to it. <p>
 */
IDeviceInformationDAO* FactoryDAO::getDeviceInformationDAO() {
	IDeviceInformationDAO* p_device_dao = new FileReader();
	return p_device_dao;
}

/**
 * This method creates and file reader object that implements the IFilterConfigurationDAO interface
 * and return a pointer to it. <p>
 */
IFilterConfigurationDAO* FactoryDAO::getFilterConfigurationDAO() {
	IFilterConfigurationDAO* p_filter_dao = new FileReader();
	return p_filter_dao;
}

/**
 * This method creates and connection object that implements the IReportDAO interface and returns
 * a pointer to that object, also sets its connection configuration. <p>
 */
IReportDAO* FactoryDAO::getReportDAO() {
	FileReader file_reader;
	ConnectionConfig* p_conn_config = file_reader.getWebserviceConfig();
	Connection* p_connection = new Connection();
	p_connection->setConnectionConfig(p_conn_config);
	return p_connection;
}

} /* namespace Factory */
