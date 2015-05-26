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
	for(int indice = 0; indice < mpListaObservadores->size(); indice++)
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
 * @name notificar
 * @param
 * - rpObserver : IObserver* (Puntero a un objeto IObserver)
 * @return
 * - void
 * @Descrition
 * Este metodo se encarga de notificar a todos los observadores de la clase el reporte
 * el cual es enviado como puntero por medio de una llamada a la funcion procesarReporte.
 * Este metodo verifica que el puntero al observador no sea nulo.
 */
void IObservable::notificar(Reporte* rpReporte)
{
	for(int indice = 0; indice < mpListaObservadores->size(); indice++)
	{
		IObserver* observer = (*mpListaObservadores)[indice];
		if(observer != 0)		//Verifica que el puntero no sea nulo
		{
			observer->procesarReporte(rpReporte);
		}
	}
}

