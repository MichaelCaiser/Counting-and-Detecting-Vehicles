/*
 * ConstantesFile.hpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * @Description:
 * Header que incluye la definicion de constantes para el analisis de texto plano del archivo
 * de configuracion, asi como la direccion de ubicacion de dicho archivo.
 */

#ifndef CONSTANTESFILE_HPP_
#define CONSTANTESFILE_HPP_

//Bibliotecas
#include <string>
using std::string;

/*
 *	ARCHIVO
 */
const string FILE_NAME = "Data/config.txt";	//Nombre del archivo donde se recolectan los datos

/*
 *	Sintaxis del archivo de configuracion
 */
const string SEPARATOR_NORMAL = "=";		//Separador normal de informacion por linea en un archivo de texto
const string SEPARATOR_SPECIAL = ",";		//Separador especial de informacion por linea en un archivo de texto
const char COMMENT = '#';					//Caracter indicador que la linea es un comentario
const string ID_ROI = "ROI";				//Identificador de la Region de Interes
const string ID_RIGH_LINE = "RL";			//Identificador de la Linea Derecha
const string ID_LEFT_LINE = "LL";			//Identificador de la Linea Izquierda
const string ID_SECURITY_TOKEN = "TOKEN";	//Identificador del SecurityToken
const string ID_EMBEDDED_CODE = "CODE";		//Identificador del Codigo del Dispostivo
const string ID_PORT = "PORT";				//Identificador del puerto de la conexion al WebService
const string ID_HOST = "HOST";				//Identificador del host correspondiente al WebService
const string ID_URL_POST = "POST-URL";		//Identificador del URL del webservice para el post de reportes

/*
 *	Estructura de la informacion de Region de Interes
 */
const int SIZE_ROI = 4; 					//Tamano de la cantidad de argumentos del ROI
const int POS_X_ROI = 0;					//Ubicacion de la posicion X de la ROI en el archivo
const int POS_Y_ROI = 1;					//Ubicacion de la posicion Y de la ROI en el archivo
const int POS_ANCHO_ROI = 2;				//Ubicacion del ancho de la ROI en el archivo
const int POS_ALTO_ROI = 3;					//Ubicacion del alto de la ROI en el archivo

/*
 *	Estructura de la informacion de Linea Derecha
 */
const int SIZE_RL = 4;						//Tamano de la cantidad de argumentos de la Linea Derecha
const int POS_X1_RL = 0;					//Ubicacion de la posicion X1 de la linea derecha en el archivo
const int POS_Y1_RL = 1;					//Ubicacion de la posicion Y1 de la linea derecha en el archivo
const int POS_X2_RL = 2;					//Ubicacion de la posicion X2 de la linea derecha en el archivo
const int POS_Y2_RL = 3;					//Ubicacion de la posicion Y2 de la linea derecha en el archivo

/*
 *	Estructura de la informacion de Linea Izquierda
 */
const int SIZE_LL = 4;						//Tamano de la cantidad de argumentos de la Linea izquierda
const int POS_X1_LL = 0;					//Ubicacion de la posicion X1 de la linea derecha en el archivo
const int POS_Y1_LL = 1;					//Ubicacion de la posicion Y1 de la linea derecha en el archivo
const int POS_X2_LL = 2;					//Ubicacion de la posicion X2 de la linea derecha en el archivo
const int POS_Y2_LL = 3;					//Ubicacion de la posicion Y2 de la linea derecha en el archivo

/*
 *	Estructura de la informacion del Security Token
 */
const int SIZE_TOKEN = 2;					//Tamano de la cantidad de argumentos de la informacion del security Token
const int POS_USER_TOKEN = 0;				//Ubicacion del username del security token en el archivo
const int POS_PASS_TOKEN = 1;				//Ubicacion del password del security token en el archivo



#endif /* CONSTANTESFILE_HPP_ */
