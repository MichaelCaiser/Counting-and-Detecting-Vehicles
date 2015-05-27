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
const string OBJETO_INI = "{";
const string OBJETO_FIN = "}";

//Constantes de Atributo JSON
const string ATRIBUTO_COMILLA    = "\"";
const string ATRIBUTO_DECLARADOR = ":";
const string ATRIBUTO_SEPARADOR  = ",";

//Constantes de Lista JSON
const string LISTA_INI = "[";
const string LISTA_FIN = "]";
const string LISTA_SEPARADOR = ",";

//Constantes de Float
const string FLOAT_PUNTO    = ".";
const string FLOAT_CERO_END = ".0";

//Constantes de clase RegistroVehiculo
const string REGISTRO_FECHA     = "\"fecha\"";
const string REGISTRO_PLACA     = "\"placa\"";
const string REGISTRO_VELOCIDAD = "\"velocidad\"";
const string REGISTRO_TIPO      = "\"tipo\"";

//Constantes de Clase Reporte
const string REPORTE_FECHA_INICIO = "\"fechainicio\"";
const string REPORTE_FECHA_FINAL  = "\"fechafinal\"";
const string REPORTE_HUMEDAD = "\"humedad\"";
const string REPORTE_TEMPERATURA = "\"temperatura\"";
const string REPORTE_LUMINOSIDAD = "\"luminosidad\"";
const string REPORTE_REGISTROS = "\"Registros\"";

#endif /* CONSTANTESJSON_HPP_ */
