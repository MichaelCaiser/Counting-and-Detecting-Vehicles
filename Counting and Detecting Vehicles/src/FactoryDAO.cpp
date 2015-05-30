/*
 * FactoryDAO.cpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 */

#include "FactoryDAO.hpp"

/*
 *********************************************************************************
 *                           Constructor y Destructor                            *
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
 *                                 Getters                                       *
 *********************************************************************************
 */

IReporteDAO* FactoryDAO::getReporteDAO()
{
	FileReader* reader = new FileReader();
	ConnectionConfiguration* config = reader->getConnectionConfiguration();
	if(config == NULL)
	{
		return NULL;
	}

	WebServiceConnection* webservice = new WebServiceConnection();
	webservice->setConnectionConfiguration(*config);

	delete reader;
	delete config;
	return webservice;
}

ISecurityDAO* FactoryDAO::getSecurityDAO()
{
	FileReader* reader = new FileReader();
	return reader;
}

IFilterConfigurationDAO* FactoryDAO::getFilgerConfigurationDAO()
{
	FileReader* reader = new FileReader();
	return reader;
}

