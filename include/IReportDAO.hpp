/*
 * @file		IReportDAO.hpp
 * @version 	1.0
 * @author 		Alonso Loaiza Pereira
 * @e-mail 		aloaizapereira@gmail.com
 * @university: Tecnológico de Costa Rica (TEC)
 *
 * @description
 * 		Interface to access the reports (DAO, Data Access Object). This interface defines the method to
 * 		save the reports in the persistence layer.
 */

#ifndef IREPORTDAO_HPP_
#define IREPORTDAO_HPP_

//Library
#include "Report.hpp"

//Specification of classes by namespace
using Model::Report;

namespace DAO
{
	class IReportDAO {
	public:
		//Destructor
		virtual ~IReportDAO(){};

		//Abstract Methods

		/**
		 * This method save a report object in the persistence layer (normally in a database). <p>
		 *
		 * @param	rReport		The report which will be stored in the persistent layer.
		 */
		virtual void save(Report &rReport) = 0;
	};
}



#endif /* IREPORTDAO_HPP_ */
