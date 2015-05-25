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

RegistroVehiculo::RegistroVehiculo()
{
	// TODO Auto-generated constructor stub
	//Datos default
	mFecha = time(0);	//Fecha Actual
	mPlaca = "ABC123";
	mVelocidadPromedio = 0;
	mTipoVehiculo = "Liviano";
}

RegistroVehiculo::RegistroVehiculo(time_t rFecha, string rPlaca, float rVelocidad, string rTipo)
{
	// TODO Auto-generated constructor stub
	mFecha = rFecha;	//Fecha Actual
	mPlaca = rPlaca;
	mVelocidadPromedio = rVelocidad;
	mTipoVehiculo = rTipo;
}

RegistroVehiculo::~RegistroVehiculo()
{
	// TODO Auto-generated destructor stub
}

/*
 *********************************************************************************
 *                                 Getters                                       *
 *********************************************************************************
 */
time_t RegistroVehiculo::getFecha()
{
	return mFecha;
}

string RegistroVehiculo::getPlaca()
{
	return mPlaca;
}

float  RegistroVehiculo::getVelocidadPromedio()
{
	return mVelocidadPromedio;
}

string RegistroVehiculo::getTipoVehiculo()
{
	return mTipoVehiculo;
}

/*
 *********************************************************************************
 *                                 Setters                                       *
 *********************************************************************************
 */
void RegistroVehiculo::setFecha(time_t rFecha)
{
	mFecha = rFecha;
}

void RegistroVehiculo::setPlaca(string rPlaca)
{
	mPlaca = rPlaca;
}

void RegistroVehiculo::setVelocidadPromedio(float rVelocidad)
{
	mVelocidadPromedio = rVelocidad;
}

void RegistroVehiculo::setTipoVehiculo(string rTipo)
{
	mTipoVehiculo = rTipo;
}


