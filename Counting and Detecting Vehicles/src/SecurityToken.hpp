/*
 * SecurityToken.hpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * @Description:
 * Es una clase simple almacenadora de Informacion (POJO), que almacena las credenciales de
 * seguridad para el envio de informacion a traves del webservice. Dichas credenciales corresponden
 * a un nombre de usuario y su respectiva password.
 */

//Bibliotecas
#include <string>

//Namespace especificacion
using std::string;

#ifndef SECURITYTOKEN_HPP_
#define SECURITYTOKEN_HPP_

class SecurityToken
{
public:

	//Constructor y Destructor
	SecurityToken();
	virtual ~SecurityToken();

	//Getters
	string getUsername();
	string getPassword();

	//Setters
	void setUsername(string rUser);
	void setPassword(string rPassword);

private:

	//Atributos
	string mUsername;	//Nombre de usuario
	string mPassword;	//Contrasena del usuario
};

#endif /* SECURITYTOKEN_HPP_ */
