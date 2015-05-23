/*
 * FileReader.hpp
 *
 * Author: Alonso Loaiza Pereira
 * e-mail: hiyitsu@gmail.com
 * University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * Description: Clase encargada de realizar un  analisis sintactico de datos almacenados en un archivo de
 * texto, ademas de la conversion de dichos datos a objetos contenedores de informacion.
 */

//Bibliotecas
#include <iostream>		//Biblioteca para realizar prints en consola
#include <string>		//Biblioteca para la manipulacion de string
#include <fstream>		//Biblioteca para la manipulacion de archivos
#include <sstream>		//Biblioteca para la realizar split de strings
#include <vector>		//Biblioteca que permite manipulacion de vectores
#include <cstdlib>		//Biblioteca que permite convertir strings a numeros enteros
#include "IConfiguracionDAO.hpp"	//Interfaz que utiliza la clase
#include "ConstantesArchivo.hpp"	//Constantes del archivo
using namespace std;

#ifndef FILEREADER_HPP_
#define FILEREADER_HPP_

class FileReader : public IConfiguracionDAO
{

public:

	//Constructor y Destructor
	FileReader();
	virtual ~FileReader();

	//Getters
	ConfiguracionConexion* getConfiguracionConexion();
	ConfiguracionEmpotrado* getConfiguracionDispositivo();
	Region* getROI();
	Linea* getLineaDerecha();
	Linea* getLineaIzquierda();
	vector<string>* splitString(string rString, string rDelimitador);

private:

	//Metodos

	bool esNumero(string rString);
	string buscarValor(string rIdentificador);




};

#endif /* FILEREADER_HPP_ */
