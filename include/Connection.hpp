/**
 * @file	Connection.hpp
 * @version	1.0
 * @author	Alonso Loaiza Pereira
 * @e-mail	aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 *
 * @description:
 * 		This class established a connection with a web service through a specific port, host and Url for
 * 		send a report object in a json format by a http request.<p>
 */

#ifndef CONNECTION_HPP_
#define CONNECTION_HPP_

//Libraries
#include "IReportDAO.hpp"
#include "ConnectionConfig.hpp"

//Specification by namespace
using DAO::IReportDAO;

namespace WebService
{
	class Connection : public IReportDAO {
	public:
		//Constructor and Destructor
		Connection();
		virtual ~Connection();

		//Setters
		void setConnectionConfig(ConnectionConfig* prConnectionConfig);
		void save(Report &rReport);

	private:
		//Attributes
		ConnectionConfig* pmConfiguration;	/* The connection configuration (port, host and url) */
	};

} /* namespace WebService */

#endif /* CONNECTION_HPP_ */
