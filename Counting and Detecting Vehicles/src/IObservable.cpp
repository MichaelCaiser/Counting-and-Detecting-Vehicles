/*
 * IObservable.cpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 */

#include "IObservable.hpp"

/*
 *********************************************************************************
 *                           Constructor y Destructor                            *
 *********************************************************************************
 */

IObservable::IObservable() {
	//Constructor
	mpListaObservadores = new vector<IObserver*>();	//Crea la lista de observadores
}

IObservable::~IObservable() {
	//Destructor
	mpListaObservadores->clear();	//Limpia la lista de observadores
	delete mpListaObservadores;		//elmina la lista
}

/*
 *********************************************************************************
 *                                 Metodos                                       *
 *********************************************************************************
 */

/*
 * @name agregarObservador
 * @param
 * - rpObserver : IObserver* (Puntero a un objeto IObserver)
 * @return
 * - void
 * @Descrition
 * Este metodo agrega el puntero de un objeto IObserver a la lista de observadores de
 * la clase los cuales seran notificados.
 */
void IObservable::agregarObservador(IObserver* rpObserver)
{
	mpListaObservadores->push_back(rpObserver);
}

/*
 * @name eliminarObservador
 * @param
 * - rpObserver : IObserver* (Puntero a un objeto IObserver)
 * @return
 * - void
 * @Descrition
 * Este metodo elimina el puntero de un objeto IObserver de la lista de observadores.
 */
void IObservable::eliminarObservador(IObserver* rpObserver)
{
	for(unsigned int indice = 0; indice < mpListaObservadores->size(); indice++)
	{
		IObserver* observer = (*mpListaObservadores)[indice];
		if(observer == rpObserver)		//Compara si son el mismo puntero
		{
			mpListaObservadores->erase(mpListaObservadores->begin()+indice);	//Elimina al observador de la lista
			return;
		}
	}
}

/*
 * @name eliminarObservadores
 * @param
 * @return
 * - void
 * @Descrition
 * Este metodo elimina todos los observadores de la lista de observadores.
 */
void IObservable::eliminarObservadores()
{
	mpListaObservadores->clear();	//Limpia la lista
}

/*
 * @name notificar
 * @param
 * - rpObserver : IObserver* (Puntero a un objeto IObserver)
 * @return
 * - void
 * @Descrition
 * Este metodo se encarga de notificar a todos los observadores de la clase el registro de un vehiculo
 * el cual es enviado como puntero por medio de una llamada a la funcion procesarRegistro. Este metodo
 * verifica que el puntero al observador no sea nulo.
 */
void IObservable::notificar(RegistroVehiculo* rpRegistro)
{
	for(unsigned int indice = 0; indice < mpListaObservadores->size(); indice++)
	{
		IObserver* observer = (*mpListaObservadores)[indice];
		if(observer != 0)		//Verifica que el puntero no sea nulo
		{
			observer->procesarRegistro(rpRegistro);
		}
	}
}

