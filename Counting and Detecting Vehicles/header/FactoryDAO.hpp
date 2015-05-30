/*
 * FactoryDAO.hpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * @Description:
 * Clase encargada de crear las clases de Acceso a Datos (DAO) implementado de esta manera el patron
 * de diseño Factory.
 */

#ifndef FACTORYDAO_HPP_
#define FACTORYDAO_HPP_

//Bibliotecas
#include "IReporteDAO.hpp"				//Interfaz ReporteDAO
#include "ISecurityDAO.hpp"				//Interfaz SecurityDAO
#include "IFilterConfigurationDAO.hpp"	//Interfaz FilterConfigurationDAO
#include "FileReader.hpp"				//Clase FileReader
#include "WebServiceConnection.hpp"		//Clase WebServiceConnection

class FactoryDAO
{
public:

	// Constructor y Destructor
	FactoryDAO();
	virtual ~FactoryDAO();

	//Getters
	IReporteDAO* getReporteDAO();
	ISecurityDAO* getSecurityDAO();
	IFilterConfigurationDAO* getFilgerConfigurationDAO();
};

#endif /* FACTORYDAO_HPP_ */
