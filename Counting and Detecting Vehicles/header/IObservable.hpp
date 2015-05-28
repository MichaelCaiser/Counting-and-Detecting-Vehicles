/*
 * IObservable.hpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * @Descrition
 * Clase que se encarga de notificar un registro de vehiculo a todos sus observadores (IObserver),
 * los cuales se agregan a un vector de observadores (mpListaObservadores). Dichos observadores
 * tambien pueden ser eliminados si asi se desea. Esta clase corresponde a la implementacion del
 * patron de diseño observer y observable.
 *
 * Explicacion del patron: http://en.wikipedia.org/wiki/Observer_pattern
 */

#ifndef IOBSERVABLE_HPP_
#define IOBSERVABLE_HPP_

//Bibliotecas
#include <vector>				//Manejo de Listas
#include "IObserver.hpp"		//Clase Abstracta IObserver
#include "RegistroVehiculo.hpp"	//Clase RegistroVehiculo

//Especificacion de clases por namespace
using std::vector;

class IObservable
{
public:

	//Constructor y Destructor
	IObservable();
	virtual ~IObservable();

	//Metodos
	void agregarObservador(IObserver* rpObserver);
	void eliminarObservador(IObserver* rpObserver);
	void eliminarObservadores();
	void notificar(RegistroVehiculo* rpRegistro);

private:

	//Atributos
	vector<IObserver*>* mpListaObservadores;

};

#endif /* IOBSERVABLE_HPP_ */
