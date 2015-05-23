/*
 * ConstantesArchivo.hpp
 *
 *  Created on: 20/4/2015
 *      Author: alonso
 */

#include <string>
using namespace std;

#ifndef CONSTANTESARCHIVO_HPP_
#define CONSTANTESARCHIVO_HPP_

const string FILE_NAME = "Data/config.txt";	//Nombre del archivo donde se recolectan los datos

/*
 *
 */
const string SEPARATOR_NORMAL = "=";		//Separador normal de informacion por linea un archivo de texto
const string SEPARATOR_SPECIAL = ",";		//Separador especial de informacion por linea un archivo de texto
const char COMMENT = '#';					//Caracter indicador que la linea leida es un comentario
const string ID_ROI = "ROI";				//Identificador de Region de Interes
const string ID_RIGH_LINE = "RL";			//Identificador de la Linea Derecha
const string ID_LEFT_LINE = "LL";			//Identificador de la Linea Izquierda
const string ID_PORT = "PORT";				//Identificador de el Puerto de la Conexion al WebService
const string ID_IP = "IP";					//Identificador de la direccion IP del HOST del WebService

/*
 *
 */
const int SIZE_ROI = 4; 					//Tamano de la cantidad de argumentos del ROI
const int POS_X_ROI = 0;					//Ubicacion de la posicion X de la ROI en el archivo
const int POS_Y_ROI = 1;					//Ubicacion de la posicion Y de la ROI en el archivo
const int POS_ANCHO_ROI = 2;				//Ubicacion del ancho de la ROI en el archivo
const int POS_ALTO_ROI = 3;					//Ubicacion del alto de la ROI en el archivo

/*
 *
 */
const int SIZE_RL = 4;						//Tamano de la cantidad de argumentos de la Linea Derecha
const int POS_X1_RL = 0;					//Ubicacion de la posicion X1 de la linea derecha en el archivo
const int POS_Y1_RL = 1;					//Ubicacion de la posicion Y1 de la linea derecha en el archivo
const int POS_X2_RL = 2;					//Ubicacion de la posicion X2 de la linea derecha en el archivo
const int POS_Y2_RL = 3;					//Ubicacion de la posicion Y2 de la linea derecha en el archivo

/*
 *
 */
const int SIZE_LL = 4;						//Tamano de la cantidad de argumentos de la Linea izquierda
const int POS_X1_LL = 0;					//Ubicacion de la posicion X1 de la linea derecha en el archivo
const int POS_Y1_LL = 1;					//Ubicacion de la posicion Y1 de la linea derecha en el archivo
const int POS_X2_LL = 2;					//Ubicacion de la posicion X2 de la linea derecha en el archivo
const int POS_Y2_LL = 3;					//Ubicacion de la posicion Y2 de la linea derecha en el archivo


#endif /* CONSTANTESARCHIVO_HPP_ */
