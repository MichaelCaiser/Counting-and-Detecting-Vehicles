/*
 * Reporte.cpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 */

#include "Reporte.hpp"

/*
 *********************************************************************************
 *                           Constructor y Destructor                            *
 *********************************************************************************
 */
Reporte::Reporte() {
	// Valores Default
	mHumedad = 0;
	mTemperatura = 0;
	mLuminosidad = 0;
}

Reporte::~Reporte() {
	// TODO Auto-generated destructor stub
}

/*
 *********************************************************************************
 *                                 Getters                                       *
 *********************************************************************************
 */

time_t Reporte::getFechaInicioReporte() {
	return mFechaInicioReporte;
}

time_t Reporte::getFechaFinalReporte() {
	return mFechaFinalReporte;
}

float  Reporte::getHumedad() {
	return mHumedad;
}

float  Reporte::getTemperatura() {
	return mTemperatura;
}

float  Reporte::getLuminosidad() {
	return mLuminosidad;
}

vector<RegistroVehiculo> Reporte::getRegistros() {
	return mRegistros;
}

/*
 *********************************************************************************
 *                                 Setters                                       *
 *********************************************************************************
 */

void Reporte::setFechaInicioReporte(time_t rFechaInicio) {
	mFechaInicioReporte = rFechaInicio;
}

void Reporte::setFechaFinalReporte(time_t rFechaFinal) {
	mFechaFinalReporte = rFechaFinal;
}

void Reporte::setHumedad(float rHumedad) {
	mHumedad = rHumedad;
}

void Reporte::setTemperatura(float rTemperatura) {
	mTemperatura = rTemperatura;
}

void Reporte::setLuminosidad(float rLuminosidad) {
	mLuminosidad = rLuminosidad;
}

/*
 *********************************************************************************
 *                                 Metodos                                       *
 *********************************************************************************
 */

/*
 * @name agregarRegistro
 * @param
 * - rRegistro : RegistroVehiculo (Registro a ser agregado al reporte)
 * @return
 * - bool (indicando si el registro fue agregado al reporte)
 * @Descrition
 * 		Metodo encargado de agregar un registro de un vehiculo al reporte, para ello verifica
 * 		que la cantidad de registros del reporte no sea superior a la establecida como maxima (100)
 * 		y agrega el registro y retorna un valor de verdad. En caso contrario retorna un valor de
 * 		falso.
 */

bool Reporte::agregarRegistro(RegistroVehiculo rRegistro)
{
	if(mRegistros.size() != MAX_REGISTROS)
	{
		mRegistros.push_back(rRegistro);
		return true;
	}
	return false;
}

/*
 * @name limpiarRegistros
 * @param
 * @return
 * @Descrition
 * 		Metodo encargo de limpiar la lista de registros del reporte.
 */
void Reporte::limpiarRegistros()
{
	mRegistros.clear();	//Vacia la lista de registros
}
