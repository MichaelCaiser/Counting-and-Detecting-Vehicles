/*
 * IReporteDAO.hpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * @Description:
 * Interfaz entre la capa de acceso a datos y la capa de logica, implementado de esta manera el
 * patron DAO (Data Access Object). Esta Interfaz es el medio a traves del cual la capa de logica
 * almacena los reportes.
 */

#ifndef IREPORTEDAO_HPP_
#define IREPORTEDAO_HPP_

//Bibliotecas
#include "Reporte.hpp"

class IReporteDAO
{
public:

	//Destructor
	virtual ~IReporteDAO(){};

	//Metodos Abstractos
	virtual void save(Reporte rReporte) = 0;
};



#endif /* IREPORTEDAO_HPP_ */
