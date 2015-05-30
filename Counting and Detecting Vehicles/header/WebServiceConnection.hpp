/*
 * WebServiceConnection.hpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * @Description:
 * Clase encargada de servir de puente de comunicacion para el almacenamiento de reportes
 * con el servidor a traves de la conexion por medio del TCP/IP. Implementa la interfaz
 * IReporteDAO.
 */

#ifndef WEBSERVICECONNECTION_HPP_
#define WEBSERVICECONNECTION_HPP_

//Bibliotecas
#include "Socket.hpp"					//Clase Socket para la conexion por TCP/IP
#include "HttpRequestBuilder.hpp"		//Clase HttpRequestBuilder para la creacion de solicitudes HTTP
#include "JsonBuilder.hpp"				//Clase JsonBuilder para la creacion de Objetos JSON
#include "ConnectionConfiguration.hpp"	//Clase ConnectionConfiguration para la configuracion de la conexion del webservice
#include "IReporteDAO.hpp"				//Interfaz IReporteDAO

class WebServiceConnection : public IReporteDAO
{
public:

	//Constructor y Destructor
	WebServiceConnection();
	virtual ~WebServiceConnection();

	//setters
	void setConnectionConfiguration(ConnectionConfiguration rConfig);

	//Metodos
	void save(Reporte rReporte);

private:

	//Atributos
	Socket* mpSocket;								//Socket para la conexion TCP/IP
	JsonBuilder* mpJsonBuilder;						//Creador de objetos JSON
	HttpRequestBuilder* mpRequestBuilder;			//Creador de consultas HTTP
	ConnectionConfiguration* mpConnectionConfig;	//Configuracion de conexion al webservie

	//Metodos
	bool connect();


};

#endif /* WEBSERVICECONNECTION_HPP_ */
