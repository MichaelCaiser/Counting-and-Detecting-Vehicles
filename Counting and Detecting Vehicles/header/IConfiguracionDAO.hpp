/*
 * IConfiguracionDAO.hpp
 *
 * Author: Alonso Loaiza Pereira
 * e-mail: hiyitsu@gmail.com
 * University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * Description: Interfaz, encargada de servir de intermediario entre la capa de logica y de
 * acceso a datos. Esto con l fin de implementar un patron de diseno DAO.
 */

//Bibliotecas
#include "ConfiguracionConexion.hpp"
#include "ConfiguracionEmpotrado.hpp"
#include "Region.hpp"
#include "Linea.hpp"


#ifndef ICONFIGURACIONDAO_HPP_
#define ICONFIGURACIONDAO_HPP_

class IConfiguracionDAO
{
	public:
		virtual ConfiguracionConexion* getConfiguracionConexion() = 0;
		virtual ConfiguracionEmpotrado* getConfiguracionDispositivo() = 0;
		virtual Region* getROI() = 0;
		virtual Linea* getLineaDerecha() = 0;
		virtual Linea* getLineaIzquierda() = 0;
};

#endif /* ICONFIGURACIONDAO_HPP_ */
