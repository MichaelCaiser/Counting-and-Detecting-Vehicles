/*
 * IConnectionConfigurationDAO.hpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * @Description:
 * Interfaz cuya principal funcion es servir como intermediaria entre la capa de acceso
 * a datos y la capa de logica, implementado de esta manera el patron DAO (Data Access Object).
 * Esta Interfaz permite obtener informacion de la conexion con el webservice como es el caso
 * del SecurityToken(Credenciales de seguridad para el webservice) asi como el codigo del
 * dispositivo (beagleboad xM). Tambien permite obtener la direccion url del webservice asi
 * como informacion relevante de dicha conexion (puerto, etc).
 */

#ifndef ICONNECTIONCONFIGURATIONDAO_HPP_
#define ICONNECTIONCONFIGURATIONDAO_HPP_

//Bibliotecas
#include <string>					//Manejo de strings
#include "SecurityToken.hpp"		//Clase SecurityToken
#include "HttpConfiguration.hpp"	//Clase HttpConfiguration

//Especificacion de clases por namespace
using std::string;

class IConnectionConfigurationDAO
{
public:
	//Destructor
	virtual ~IConnectionConfigurationDAO(){};

	//Metodos Abstractos
	virtual string* 			getCodigoDispositivo() = 0;
	virtual SecurityToken*  	getSecurityToken() = 0;
	virtual HttpConfiguration*  getHttpConfiguration() = 0;
};



#endif /* ICONNECTIONCONFIGURATIONDAO_HPP_ */
