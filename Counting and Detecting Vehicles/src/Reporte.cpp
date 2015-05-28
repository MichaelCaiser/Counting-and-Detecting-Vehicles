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
	// Inicializa los punteros
	mpCodigoDispositivo = new string();
	mpFechaInicioReporte = new time_t();
	mpFechaFinalReporte = new time_t();
	mpHumedad = new float();
	mpTemperatura = new float();
	mpLuminosidad = new float();
	mpCredenciales = new SecurityToken();
	mpRegistros = new vector<RegistroVehiculo*>();
}

Reporte::~Reporte()
{
	limpiarRegistros();	//Vacia la lista de registros eliminado cada uno de ellos

	//Libera la memoria
	delete mpCodigoDispositivo;
	delete mpFechaInicioReporte;
	delete mpFechaFinalReporte;
	delete mpHumedad;
	delete mpTemperatura;
	delete mpLuminosidad;
	delete mpCredenciales;
	delete mpRegistros;
}

/*
 *********************************************************************************
 *                                 Getters                                       *
 *********************************************************************************
 */

string Reporte::getCodigoDispositivo() {
	return *mpCodigoDispositivo;
}

time_t Reporte::getFechaInicioReporte() {
	return *mpFechaInicioReporte;
}

time_t Reporte::getFechaFinalReporte() {
	return *mpFechaFinalReporte;
}

float  Reporte::getHumedad() {
	return *mpHumedad;
}

float  Reporte::getTemperatura() {
	return *mpTemperatura;
}

float  Reporte::getLuminosidad() {
	return *mpLuminosidad;
}

SecurityToken Reporte::getSecurityToken() {
	return *mpCredenciales;
}

vector<RegistroVehiculo*> Reporte::getRegistros() {
	return *mpRegistros;
}

/*
 *********************************************************************************
 *                                 Setters                                       *
 *********************************************************************************
 */

void Reporte::setCodigoDispositivo(string rCodigo) {
	*mpCodigoDispositivo = rCodigo;
}

void Reporte::setFechaInicioReporte(time_t rFechaInicio) {
	*mpFechaInicioReporte = rFechaInicio;
}

void Reporte::setFechaFinalReporte(time_t rFechaFinal) {
	*mpFechaFinalReporte = rFechaFinal;
}

void Reporte::setHumedad(float rHumedad) {
	*mpHumedad = rHumedad;
}

void Reporte::setTemperatura(float rTemperatura) {
	*mpTemperatura = rTemperatura;
}

void Reporte::setLuminosidad(float rLuminosidad) {
	*mpLuminosidad = rLuminosidad;
}

void Reporte::setSecurityToken(SecurityToken rToken) {
	*mpCredenciales = rToken;
}

/*
 *********************************************************************************
 *                                 Metodos                                       *
 *********************************************************************************
 */

/*
 * @name agregarRegistro
 * @param
 * - rpRegistro : RegistroVehiculo (Puntero de un registro que se desea anadir al reporte)
 * @return
 * - bool (indicando si el puntero del registro fue agregado al reporte)
 * @Descrition
 * 		Metodo encargado de agregar un puntero de un registro de un vehiculo al reporte, para ello
 * 		verifica que la cantidad de punteros a registros del reporte no sea superior a la establecida
 * 		como maxima (100), para posteriormente agregar el registro y retornar un valor de verdad.
 * 		En caso contrario retorna un valor de falso.
 */

bool Reporte::agregarRegistro(RegistroVehiculo* rpRegistro)
{
	if(mpRegistros->size() != MAX_REGISTROS)
	{
		mpRegistros->push_back(rpRegistro);
		return true;
	}
	return false;
}

/*
 * @name limpiarRegistros
 * @param
 * @return
 * @Descrition
 * Metodo encargo de limpiar la lista de registros del reporte. Eliminado cada uno de los objetos
 * que contiene la lista.
 */
void Reporte::limpiarRegistros()
{
	for(unsigned int indice = 0; indice < mpRegistros->size(); indice++)
	{
		RegistroVehiculo* puntero_registro = (*mpRegistros)[indice];
		delete puntero_registro;
	}
	mpRegistros->clear();	//Libera la lista
}
