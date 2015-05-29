/*
 * RegistroVehiculo.cpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 */

#include "RegistroVehiculo.hpp"


/*
 *********************************************************************************
 *                           Constructor y Destructor                            *
 *********************************************************************************
 */

RegistroVehiculo::RegistroVehiculo() {
	// Constructor
	mVelocidadPromedio = 0.0f;
	mFecha = time(0);
}

RegistroVehiculo::RegistroVehiculo(string rPlaca, string rTipo, float rVelocidad, time_t rFecha)
{
	// Asigna valor a los atributos
	mPlaca = rPlaca;
	mTipoVehiculo = rTipo;
	mVelocidadPromedio = rVelocidad;
	mFecha = rFecha;
}

RegistroVehiculo::~RegistroVehiculo() {
	// Destructor
}

/*
 *********************************************************************************
 *                                 Getters                                       *
 *********************************************************************************
 */

string RegistroVehiculo::getPlaca()
{
	return mPlaca;
}

string RegistroVehiculo::getTipoVehiculo()
{
	return mTipoVehiculo;
}

float  RegistroVehiculo::getVelocidadPromedio()
{
	return mVelocidadPromedio;
}

time_t RegistroVehiculo::getFecha()
{
	return mFecha;
}

/*
 *********************************************************************************
 *                                 Setters                                       *
 *********************************************************************************
 */

void RegistroVehiculo::setPlaca(string rPlaca)
{
	mPlaca = rPlaca;
}

void RegistroVehiculo::setTipoVehiculo(string rTipo)
{
	mTipoVehiculo = rTipo;
}

void RegistroVehiculo::setVelocidadPromedio(float rVelocidad)
{
	mVelocidadPromedio = rVelocidad;
}

void RegistroVehiculo::setFecha(time_t rFecha)
{
	mFecha = rFecha;
}







