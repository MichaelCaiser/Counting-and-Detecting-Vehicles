/*
 * IObserver.hpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * @Description:
 * Clase abstracta es decir no puede ser inicializada, la cual funciona como una interfaz (Como en Java)
 * que declara un metodo virtual notificarReporte, el cual debe ser sobreescrito en la clase que herede
 * de esta. Esta clase es una implementacion del patron de diseño Observer and Observable.
 *
 * Explicacion del patron: http://en.wikipedia.org/wiki/Observer_pattern
 */

#ifndef IOBSERVER_HPP_
#define IOBSERVER_HPP_

//Bibliotecas
#include "Reporte.hpp"	//Clase Reporte

class IObserver
{
public:

	//Destructor
	virtual ~IObserver() {};

	//Metodos Abstractos
	virtual void procesarReporte(Reporte* rpReporte) = 0;
};

#endif /* IOBSERVER_HPP_ */
