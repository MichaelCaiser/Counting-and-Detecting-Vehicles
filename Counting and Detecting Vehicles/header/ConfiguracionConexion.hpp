/*
 * ConfiguracionConexion.hpp
 *
 * Author: Alonso Loaiza Pereira
 * e-mail: hiyitsu@gmail.com
 * University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * Description: Clase encargada de almacenar la informacion de la conexion con el web service,
 * almacenando informacion como el puerto y la direccion IP.
 */

//Bibliotecas
#include <string>			//Biblioteca para el manejo de string
using namespace std;

#ifndef CONFIGURACIONCONEXION_HPP_
#define CONFIGURACIONCONEXION_HPP_

class ConfiguracionConexion
{
	public:

		//Constructor y Destructor
		ConfiguracionConexion(int rPuerto, string rIP);
		virtual ~ConfiguracionConexion();

		//Getters
		int getPuerto();
		string getDireccionIP();

		//Setters
		void setPuerto(int rPuerto);
		void setDireccionIP(string rDireccionIP);

	private:

		//Atributos
		int mPuerto;			//Puerto por el que se realizara la conexion TCP/IP
		string* mDireccionIP;	//Direccion IP con la que se realizara la conexion TCP/IP
};

#endif /* CONFIGURACIONCONEXION_HPP_ */
