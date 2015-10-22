/**
 * @file	ConnectionConfig.hpp
 * @version	1.0
 * @author	Alonso Loaiza Pereira
 * @e-mail	aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 *
 * @description
 * 		This class..
 */

#ifndef CONNECTIONCONFIG_HPP_
#define CONNECTIONCONFIG_HPP_

#include <string>
using std::string;

namespace WebService
{
	class ConnectionConfig {
	public:
		//Constructor and Destructor
		ConnectionConfig(int rPort, string rHost, string rUrl);
		virtual ~ConnectionConfig();

		//Getters
		int getPort() const;
		string getHost() const;
		string getUrl() const;

		//Setters
		void setPort(int rPort);
		void setHost(string rHost);
		void setUrl(string rUrl);

	private:
		//Attributes
		int mPort;
		string mHost;
		string mUrl;
	};

} /* namespace WebService */

#endif /* CONNECTIONCONFIG_HPP_ */
