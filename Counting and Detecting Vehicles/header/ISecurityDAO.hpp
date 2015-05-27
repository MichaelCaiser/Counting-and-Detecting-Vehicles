/*
 * ISecurityDAO.hpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * @Description:
 * Interfaz entre la capa de acceso a datos y la capa de logica, implementado de esta manera el
 * patron DAO (Data Access Object). Esta Interfaz es el medio a traves del cual la capa de logica
 * obtiene las credenciales de seguridad necesarias, como es el caso del security token y el
 * codigo del dispositivo emisor de reportes.
 */

#ifndef ISECURITYDAO_HPP_
#define ISECURITYDAO_HPP_

//Bibliotecas
#include <string>				//Definicion y manejo de String
#include "SecurityToken.hpp"	//Clase Security Token

//Especificacion de clases por namespace
using std::string;

class ISecurityDAO
{
public:

	//Destructor
	virtual ~ISecurityDAO(){};

	//Metodos Abstractos
	virtual SecurityToken* getSecurityToken() = 0;
	virtual string*        getCodigoDispositivo() = 0;
};



#endif /* ISECURITYDAO_HPP_ */
