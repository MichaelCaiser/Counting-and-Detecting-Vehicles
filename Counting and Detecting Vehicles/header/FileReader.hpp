/*
 * FileReader.hpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * @Description:
 * Clase encargada de realizar un  analisis sintactico de datos almacenados en un archivo de
 * texto, ademas de la conversion de dichos datos a objetos contenedores de informacion.
 */

//Bibliotecas
#include <string>			//Biblioteca para la manipulacion de string
#include <vector>			//Biblioteca que permite manipulacion de vectores
#include "Region.hpp"					//Clase Region
#include "Linea.hpp"					//Clase Linea
#include "SecurityToken.hpp"			//Clase SecurityToken
#include "ConnectionConfiguration.hpp"	//Clase ConnectionConfiguration
#include "ISecurityDAO.hpp"				//Interfaz ISecurityDAO
#include "IFilterConfigurationDAO.hpp"	//Interfaz IFilterConfigurationDAO

//Especificacion de clases por namespace
using std::string;
using std::vector;

#ifndef FILEREADER_HPP_
#define FILEREADER_HPP_

class FileReader : public IFilterConfigurationDAO, public ISecurityDAO
{

public:

	//Constructor y Destructor
	FileReader();
	virtual ~FileReader();

	//Getters
	ConnectionConfiguration* getConnectionConfiguration();

	//Interfaz IFilterConfigurationDAO
	Region* getROI();
	Linea*  getLineaDerecha();
	Linea*  getLineaIzquierda();

	//Interfaz ISecurityDAO
	SecurityToken* getSecurityToken();
	string*        getCodigoDispositivo();

private:

	//Metodos
	bool esNumero(string rString);
	string buscarValor(string rIdentificador);
	vector<string> splitString(string rString, string rDelimitador);
};

#endif /* FILEREADER_HPP_ */
