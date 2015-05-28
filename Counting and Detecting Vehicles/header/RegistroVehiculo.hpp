/*
 * RegistroVehiculo.hpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * @Description:
 * Clase encargada de almacenar la informacion (Simple POJO) sobre el conteo de un vehiculo como lo es el caso
 * de la fecha en la que se realizo la captura, la velocidad promedio del vehiculo, el tipo de vehiculo y su
 * placa.
 */

#ifndef REGISTROVEHICULO_HPP_
#define REGISTROVEHICULO_HPP_

//Bibliotecas
#include <ctime>		//Manejo de Dates (time_t)
#include <string>		//Manejo de Strings

//Especificacion de Namespace
using std::time_t;
using std::string;

class RegistroVehiculo
{
public:

	//Constructor y Destructor
	RegistroVehiculo();
	RegistroVehiculo(string rPlaca, string rTipo, float rVelocidad, time_t rFecha);
	virtual ~RegistroVehiculo();

	//Getters
	time_t getFecha();
	string getPlaca();
	float  getVelocidadPromedio();
	string getTipoVehiculo();

	//Setters
	void setFecha(time_t rFecha);
	void setPlaca(string rPlaca);
	void setVelocidadPromedio(float rVelocidad);
	void setTipoVehiculo(string rTipo);

private:

	//Atributos
	string* mpPlaca;				//Puntero a un string con la Placa del vehiculo
	string* mpTipoVehiculo;			//Puntero a un string con el Tipo de vehiculo
	float*  mpVelocidadPromedio;	//Puntero a un float con la Velocidad con la que paso el vehiculo por la estructura vial
	time_t* mpFecha;				//Puntero a la Fecha de la detección del vehiculo
};

#endif /* REGISTROVEHICULO_HPP_ */
