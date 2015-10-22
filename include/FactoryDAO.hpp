/*
 * @file	FactoryDAO.hpp
 * @version	1.0
 * @author	Alonso Loaiza Pereira
 * @e-mail	aloaizapereira@gmail.com
 * @universtity	Tecnológico de Costa Rica (TEC)
 *
 * @description:
 * 		This class creates the classes to access the data, specifically creates classes which implements
 * 		the interfaces to DataAccess. This class is a Factory of DAOs (Data Access Objects).
 */

#ifndef FACTORYDAO_HPP_
#define FACTORYDAO_HPP_

//Libraries
#include "IDeviceInformationDAO.hpp"	/* IDeviceInformationDAO interface defined in the DAO namespace */
#include "IFilterConfigurationDAO.hpp"	/* IFilterConfigurationDAO interface defined in the DAO namespace */
#include "IReportDAO.hpp"				/* IReportDAO interface defined in the DAO namespace */

//Specification by namespace
using DAO::IDeviceInformationDAO;
using DAO::IFilterConfigurationDAO;
using DAO::IReportDAO;


namespace Factory
{
	class FactoryDAO {
	public:
		//Constructor and Destructor
		FactoryDAO();
		virtual ~FactoryDAO();

		//Methods
		IDeviceInformationDAO* getDeviceInformationDAO();
		IFilterConfigurationDAO* getFilterConfigurationDAO();
		IReportDAO* getReportDAO();
	};

} /* namespace Factory */

#endif /* FACTORYDAO_HPP_ */
