/*
 * ConnectionConfiguration.hpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * @Description:
 * Clase simple almacenadora de informacion (POJO), dicha informacion conrresponde a la relacionada con la conexion
 * al webservice como es el caso del numero de puerto, el host y la url a traves de la cual se haran los post para
 * almacenar los reportes.
 */

#ifndef CONNECTIONCONFIGURATION_HPP_
#define CONNECTIONCONFIGURATION_HPP_

//Bibliotecas
#include <string>

//Especificacion de clases por namespace
using std::string;

class ConnectionConfiguration
{
public:

	//Constructor y Destructor
	ConnectionConfiguration();
	ConnectionConfiguration(int rPort, string rHost, string rUrl);
	virtual ~ConnectionConfiguration();

	//Getters
	int 	getPort();
	string 	getHost();
	string 	getUrlPostReport();

	//Setters
	void setPort(int rPort);
	void setHost(string rHost);
	void setUrlPostReport(string rUrl);

private:
	int mPort;				//Puerto a traves del cual se realiza la conexion
	string mHost;			//Direccion IP del host
	string mUrlPostReport;	//Direccion URL del webservice para realizar el post de reportes
};

#endif /* CONNECTIONCONFIGURATION_HPP_ */
