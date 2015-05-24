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

//Bibliotecas
#include <ctime>		//Manejo de Dates (time_t)
#include <string>		//Manejo de Strings
using namespace std;

//Constantes
//int NAME = 3;

#ifndef REGISTROVEHICULO_HPP_
#define REGISTROVEHICULO_HPP_

class RegistroVehiculo
{

public:
	//Constructor y Destructor
	RegistroVehiculo();
	RegistroVehiculo(time_t rFecha, string rPlaca, float rVelocidad, string rTipo);
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
	time_t mFecha;				//Fecha de la detección del vehiculo
	string mPlaca;				//Placa del vehiculo
	float  mVelocidadPromedio;	//Velocidad con la que paso el vehiculo por la estructura vial
	string mTipoVehiculo;		//Tipo de vehiculo


};

#endif /* REGISTROVEHICULO_HPP_ */
