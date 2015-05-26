/*
 * IFilterConfigurationDAO.hpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * @Description:
 * Interfaz cuya principal funcion es servir como intermediaria entre la capa de acceso
 * a datos y la capa de logica, implementado de esta manera el patron DAO (Data Access Object).
 * Esta Interfaz permite obtener informacion de configuracion con la que trabaja la capa de
 * logica especificamente para el filtro de imagen, como es el caso de la Region de Interes(ROI)
 * asi como los limites derecho e izquierdo de la carretera.
 */

#ifndef IFILTERCONFIGURATIONDAO_HPP_
#define IFILTERCONFIGURATIONDAO_HPP_


//Bibliotecas
#include "Region.hpp"	//Clase Region
#include "Linea.hpp"	//Cñase Linea

class IFilterConfigurationDAO
{
public:

	//Destructor
	virtual ~IFilterConfigurationDAO(){};

	//Metodos Abstractos
	virtual Region* getROI() = 0;
	virtual Linea*  getLineaDerecha() = 0;
	virtual Linea*  getLineaIzquierda() = 0;
};


#endif /* IFILTERCONFIGURATIONDAO_HPP_ */
