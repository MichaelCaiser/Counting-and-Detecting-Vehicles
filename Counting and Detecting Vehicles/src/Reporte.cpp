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
Reporte::Reporte()
{
	// Inicializa los Atributos
	mFechaInicioReporte = time(0);
	mFechaFinalReporte = time(0);
	mHumedad = 0;
	mTemperatura = 0;
	mLuminosidad = 0;
}

Reporte::~Reporte() {
	// Destructor
}

/*
 *********************************************************************************
 *                                 Getters                                       *
 *********************************************************************************
 */

string Reporte::getCodigoDispositivo() {
	return mCodigoDispositivo;
}

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

SecurityToken Reporte::getSecurityToken() {
	return mCredenciales;
}

vector<RegistroVehiculo> Reporte::getRegistros() {
	return mRegistros;
}

/*
 *********************************************************************************
 *                                 Setters                                       *
 *********************************************************************************
 */

void Reporte::setCodigoDispositivo(string rCodigo) {
	mCodigoDispositivo = rCodigo;
}

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

void Reporte::setSecurityToken(SecurityToken rToken) {
	mCredenciales = rToken;
}

/*
 *********************************************************************************
 *                                 Metodos                                       *
 *********************************************************************************
 */

/*
 * @name agregarRegistro
 * @param
 * - rRegistro : RegistroVehiculo (Registro que se desea anadir al reporte)
 * @return
 * - bool (indicando si el puntero del registro fue agregado al reporte)
 * @Descrition
 * Metodo encargado de agregar un puntero de un registro de un vehiculo al reporte, para ello
 * verifica que la cantidad de registros del reporte no sea superior a la establecida como
 * maxima (100), para posteriormente agregar el registro y retornar un valor de verdad.
 * En caso contrario retorna un valor de falso.
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
 * Metodo encargo de limpiar la lista de registros del reporte.
 */
void Reporte::limpiarRegistros()
{
	mRegistros.clear();	//Libera la lista
}
