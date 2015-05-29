/*
 * ConstantesJSON.hpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * @Description:
 * Header que incluye la definicion de constantes para la creacion de objetos por medio de
 * JSON (Java Script Object Notation).
 */

//Bibliotecas
#include <string>	//Manejo de string
using std::string;

#ifndef CONSTANTESJSON_HPP_
#define CONSTANTESJSON_HPP_

//Constantes de Objeto JSON
const string OBJETO_INI = "{";	//Inicio de un Objeto
const string OBJETO_FIN = "}";	//Final de un Objeto

//Constantes de Atributo JSON
const string ATRIBUTO_COMILLA    = "\"";	//Comilla inicial de los String en formato JSON
const string ATRIBUTO_DECLARADOR = ":";		//Separador de JSON para declarar el valor de un atributo de su nombre
const string ATRIBUTO_SEPARADOR  = ",";		//Separador de JSON para atributos

//Constantes de Lista JSON
const string LISTA_INI = "[";		//Inicio de un arreglo
const string LISTA_FIN = "]";		//Final de un arreglo
const string LISTA_SEPARADOR = ",";	//Separador de elementos del arreglo

//Constantes de Float
const string FLOAT_PUNTO    = ".";
const string FLOAT_CERO_END = ".0";	//Finalizacion de valores enteros en formato float

//Constantes de Clase Reporte
const string REPORTE_CODIGO = "\"CodigoDispositivo\"";	//Identificador del atributo CodigoDispotivo en JSON
const string REPORTE_FECHA_INICIO = "\"FechaInicio\"";	//Identificador del atributo FechaInicioReporte en JSON
const string REPORTE_FECHA_FINAL  = "\"FechaFinal\"";	//Identificador del atributo FechaFinalReporte en JSON
const string REPORTE_HUMEDAD = "\"Humedad\"";			//Identificador del atributo Humedad en JSON
const string REPORTE_TEMPERATURA = "\"Temperatura\"";	//Identificador del atributo Temperatura en JSON
const string REPORTE_LUMINOSIDAD = "\"Luminosidad\"";	//Identificador del atributo Luminosidad en JSON
const string REPORTE_SECURITYTOKEN = "\"Token\"";			//Identificador del atributo SecurityToken en JSON
const string REPORTE_REGISTROS = "\"Registros\"";		//Identificador del atributo Registros en JSON

//Constantes de clase RegistroVehiculo
const string REGISTRO_FECHA     = "\"FechaRegistro\"";		//Identificador del atributo Fecha en JSON
const string REGISTRO_PLACA     = "\"Placa\"";				//Identificador del atributo Placa en JSON
const string REGISTRO_VELOCIDAD = "\"VelocidadPromedio\"";	//Identificador del atributo VelocidadPromedio en JSON
const string REGISTRO_TIPO      = "\"TipoVehiculo\"";		//Identificador del atributo TipoVehiculo en JSON

//Constantes de Clase SecurityToken
const string TOKEN_USERNAME = "\"Username\"";	//Identificador del atributo Username en JSON
const string TOKEN_PASSWORD = "\"Password\"";	//Identificador del atributo Password en JSON

#endif /* CONSTANTESJSON_HPP_ */
