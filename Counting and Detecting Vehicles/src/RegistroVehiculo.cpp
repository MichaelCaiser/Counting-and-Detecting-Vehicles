/*
 * RegistroVehiculo.cpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 */

#include "RegistroVehiculo.hpp"

#include <iostream>
using namespace std;

/*
 *********************************************************************************
 *                           Constructor y Destructor                            *
 *********************************************************************************
 */

RegistroVehiculo::RegistroVehiculo()
{
	//Inicializa las variables
	mpPlaca = new string();
	mpTipoVehiculo = new string();
	mpVelocidadPromedio = new float();
	mpFecha = new time_t();

	cout<<"creando objeto constructor 1"<<endl;
}

RegistroVehiculo::RegistroVehiculo(string rPlaca, string rTipo, float rVelocidad, time_t rFecha)
{
	// Inicializa las variables y les asigna su valor
	mpPlaca = new string(rPlaca);
	mpTipoVehiculo = new string(rTipo);
	mpVelocidadPromedio = new float(rVelocidad);
	mpFecha = new time_t(rFecha);

	cout<<"creando objeto constructor 2"<<endl;
}

RegistroVehiculo::~RegistroVehiculo()
{
	// Libera la memoria
	delete mpPlaca;
	delete mpTipoVehiculo;
	delete mpVelocidadPromedio;
	delete mpFecha;

	cout<<"Destruyendo objeto"<<endl;
}

/*
 *********************************************************************************
 *                                 Getters                                       *
 *********************************************************************************
 */

string RegistroVehiculo::getPlaca()
{
	return *mpPlaca;
}

string RegistroVehiculo::getTipoVehiculo()
{
	return *mpTipoVehiculo;
}

float  RegistroVehiculo::getVelocidadPromedio()
{
	return *mpVelocidadPromedio;
}

time_t RegistroVehiculo::getFecha()
{
	return *mpFecha;
}

/*
 *********************************************************************************
 *                                 Setters                                       *
 *********************************************************************************
 */

void RegistroVehiculo::setPlaca(string rPlaca)
{
	*mpPlaca = rPlaca;
}

void RegistroVehiculo::setTipoVehiculo(string rTipo)
{
	*mpTipoVehiculo = rTipo;
}

void RegistroVehiculo::setVelocidadPromedio(float rVelocidad)
{
	*mpVelocidadPromedio = rVelocidad;
}

void RegistroVehiculo::setFecha(time_t rFecha)
{
	*mpFecha = rFecha;
}







