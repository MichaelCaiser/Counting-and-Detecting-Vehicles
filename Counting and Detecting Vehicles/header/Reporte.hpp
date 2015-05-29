/*
 * Reporte.hpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * @Description:
 * Clase encargada de almacenar la informacion (Simple POJO) de un reporte la cual contiene una lista con
 * los registros de los vehiculos que pasaron por la estructura, ademas de otros datos como fecha de inicio
 * del reporte y fecha final, humedad, temperatura, codigo del dispositivo, entre otros.
 */

#ifndef REPORTE_HPP_
#define REPORTE_HPP_

//Bibliotecas
#include <string>				//Manejo de String
#include <ctime>				//Manejo de Dates (time_t)
#include <vector>				//Manejo de listas
#include "RegistroVehiculo.hpp"	//Registro de un vehiculo
#include "SecurityToken.hpp"	//Credencial de seguridad

//Especificacion de Namespace
using std::string;
using std::time_t;
using std::vector;

class Reporte
{
public:

	//Constructor y Destructor
	Reporte();
	virtual ~Reporte();

	//Getters
	string getCodigoDispositivo();
	time_t getFechaInicioReporte();
	time_t getFechaFinalReporte();
	float  getHumedad();
	float  getTemperatura();
	float  getLuminosidad();
	SecurityToken getSecurityToken();
	vector<RegistroVehiculo> getRegistros();

	//Setters
	void setCodigoDispositivo(string rCodigo);
	void setFechaInicioReporte(time_t rFechaInicio);
	void setFechaFinalReporte(time_t rFechaFinal);
	void setHumedad(float rHumedad);
	void setTemperatura(float rTemperatura);
	void setLuminosidad(float rLuminosidad);
	void setSecurityToken(SecurityToken rToken);

	//Metodos
	bool agregarRegistro(RegistroVehiculo rRegistro);
	void limpiarRegistros();

private:

	//Atributos
	string mCodigoDispositivo;			//Codigo identificador del dispositivo que emite el reporte
	time_t mFechaInicioReporte;			//Fecha cuando se empieza a generar el reporte
	time_t mFechaFinalReporte;			//Fecha cuando se termina de generar el reporte
	float  mHumedad;						//Humedad promedio a la que se genero el reporte
	float  mTemperatura;					//Temperatura promedio a la que se genero el reporte
	float  mLuminosidad;					//Luminosidad promedio con la que se genero el reporte
	SecurityToken mCredenciales;			//Token de seguridad del reporte
	vector<RegistroVehiculo> mRegistros;	//Lista con los registros del reporte

	//Atributos Constantes
	static const short int MAX_REGISTROS = 100;	//Maximo cantidad de registros

};

#endif /* REPORTE_HPP_ */
