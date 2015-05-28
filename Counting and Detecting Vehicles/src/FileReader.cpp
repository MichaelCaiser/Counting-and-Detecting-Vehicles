/*
 * FileReader.cpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 */

#include "FileReader.hpp"

//Bibliotecas
#include <fstream>		//Biblioteca para la manipulacion de archivos
#include <iostream>		//Biblioteca de Input Outpu stream (Prints)
#include <stdlib.h>     //funcion atoi para la conversion de string a entero
#include "ConstantesFile.hpp"	//Header con la definicion de constantes

//Especificacion de clases por namespace
using std::ifstream;
using std::cout;		//Print
using std::endl;		//fin de linea

/*
 *********************************************************************************
 *                           Constructor y Destructor                            *
 *********************************************************************************
 */

FileReader::FileReader()
{
	// TODO Auto-generated constructor stub
}

FileReader::~FileReader()
{
	// TODO Auto-generated destructor stub
}

/*
 *********************************************************************************
 *                                 Getters                                       *
 *********************************************************************************
 */

/*
 * @name getConnectionConfiguration
 * @param void
 * @Return
 * - ConnectionConfiguration*
 * @Descrition
 * Este metodo se encarga de buscar dentro del archivo de texto de configuracion de la aplicacion (config.txt)
 * los identificadores correspondientes a la configuracion de la conexion (HOST, PORT, POST-URL) y la informacion
 * asociada a dichos identificadores para poder crear un objeto de tipo ConnectionConfiguration y devolver
 * el puntero a dicho objeto. En caso que alguno de los datos no se encuentren se retorna un puntero nulo.
 */
ConnectionConfiguration*  FileReader::getConnectionConfiguration()
{
	ConnectionConfiguration* connec_config;		//Puntero al objeto configuration connection
	string string_port = buscarValor(ID_PORT);	//Busca el valor del puerto
	string string_host = buscarValor(ID_HOST);	//Busca el valor del host
	string string_urlpostreport = buscarValor(ID_URL_POST);	//Busca el valor del url post report

	if(string_port.size() == 0 || string_host.size() == 0 ||
	   string_urlpostreport.size() == 0)		//Verifica que ninguno de los valores sean vacios
	{
		return NULL;
	}

	if(!esNumero(string_port))					//Verifica que el puerto sea un numero entero
	{
		return NULL;
	}

	int port = atoi(string_port.c_str());		//Convierte el string del puerto a entero
	connec_config = new ConnectionConfiguration(port, string_host, string_urlpostreport);	//Crea el objeto
	return connec_config;
}

/*
 * @name getROI
 * @param void
 * @Return
 * - Region*
 * @Descrition
 * Este Metodo se encarga de buscar dentro del archivo de texto de configuracion de la aplicacion (config.txt)
 * el identificador de ROI para encontrar el valor asignado a la region de interes (ROI) tanto como su posicion,
 * tamano y altura. Ademas se crea el objeto Region que contiene la informacion de la ROI y retorna un puntero
 * del mismo objeto.
 */
Region* FileReader::getROI()
{
	string valor_buscado = buscarValor(ID_ROI);
	vector<string> lista = splitString(valor_buscado, SEPARATOR_SPECIAL);	//Divide el valor buscado segun , para encontrar los 4 valores del ROI

	if(lista.size() != SIZE_ROI)											//Verifica que se haya encontrado los 4 valores de la ROI
	{
		return NULL;														//Retorna nulo dado que no se encontro el ROI en el archivo
	}

	if(!esNumero(lista.at(POS_X_ROI)) || !esNumero(lista.at(POS_Y_ROI)) ||
	   !esNumero(lista.at(POS_ANCHO_ROI)) ||!esNumero(lista.at(POS_ALTO_ROI)))	//Verifica que los valores de la lista sean numeros enteros
	{
		return NULL;															//Retorna nulo dado que los valores buscados no son numeros enteros
	}

	//Convierte los strings del vector a numeros
	int posicion_x = atoi(lista.at(POS_X_ROI).c_str());
	int posicion_y = atoi(lista.at(POS_Y_ROI).c_str());
	int ancho      = atoi(lista.at(POS_ANCHO_ROI).c_str());
	int alto 	   = atoi(lista.at(POS_ALTO_ROI).c_str());

	Region* roi = new Region(posicion_x, posicion_y, ancho, alto);			//Crea la region
	return roi;
}

/*
 * @name getLineaDerecha
 * @param void
 * @Return
 * - Linea* (un puntero al objeto linea creado)
 * @Descrition
 * Este Metodo se encarga de buscar dentro del archivo de texto de configuracion de la aplicacion (config.txt)
 * el identificador RL para encontrar los valores asignados a la linea derecha como lo son los dos puntos
 * que determinan a la recta. Ademas se crea el objeto Linea que contiene la informacion de dicha linea.
 */
Linea* FileReader::getLineaDerecha()
{
	string valor_buscado = buscarValor(ID_RIGH_LINE);
	vector<string> lista = splitString(valor_buscado, SEPARATOR_SPECIAL);		//Divide el valor buscado segun , para encontrar los 4 valores de la linea derecha

	if(lista.size() != SIZE_RL)													//Verifica que se haya encontrado los 4 valores de la ROI
	{
		return NULL;															//Retorna nulo dado que el valor buscado no es correcto
	}

	if(!esNumero(lista.at(POS_X1_RL)) || !esNumero(lista.at(POS_Y1_RL)) ||
	   !esNumero(lista.at(POS_X2_RL)) || !esNumero(lista.at(POS_Y2_RL)))		//Verifica que los valores de la lista sean numeros enteros
	{
		return NULL;															//Retorna nulo dado que los valores buscados no son numeros enteros
	}

	//Convierte los strings del vector a numeros
	int pos_x1 = atoi(lista.at(POS_X1_RL).c_str());
	int pos_y1 = atoi(lista.at(POS_Y1_RL).c_str());
	int pos_x2 = atoi(lista.at(POS_X2_RL).c_str());
	int pos_y2 = atoi(lista.at(POS_Y2_RL).c_str());

	Linea* linea_derecha = new Linea(pos_x1, pos_y1, pos_x2, pos_y2);			//Crea la linea
	return linea_derecha;
}

/*
 * @name getLineaIzquierda
 * @param void
 * @Return
 * - Linea* (un puntero al objeto linea creado)
 * @Descrition
 * Este Metodo se encarga de buscar dentro del archivo de texto de configuracion de la aplicacion (config.txt)
 * el identificador LL para encontrar los valores asiganados a la linea izquierda como lo son los dos puntos
 * que determinan a la recta. Ademas se crea el objeto Linea que contiene la informacion de dicha linea.
 */
Linea* FileReader::getLineaIzquierda()
{
	string valor_buscado = buscarValor(ID_LEFT_LINE);
	vector<string> lista = splitString(valor_buscado, SEPARATOR_SPECIAL);			//Divide el valor buscado segun , para encontrar los 4 valores de la linea izquierda

	if(lista.size() != SIZE_LL)														//Verifica que se haya encontrado los 4 valores de la ROI
	{
		return NULL;																//Retorna nulo dado que el valor buscado no es correcto
	}

	if(!esNumero(lista.at(POS_X1_LL)) || !esNumero(lista.at(POS_Y1_LL)) ||
	   !esNumero(lista.at(POS_X2_LL)) || !esNumero(lista.at(POS_Y2_LL)))		//Verifica que los valores de la lista sean numeros enteros
	{
		return NULL;															//Retorna nulo dado que los valores buscados no son numeros enteros
	}

	//Convierte los strings del vector a numeros
	int pos_x1 = atoi(lista.at(POS_X1_LL).c_str());
	int pos_y1 = atoi(lista.at(POS_Y1_LL).c_str());
	int pos_x2 = atoi(lista.at(POS_X2_LL).c_str());
	int pos_y2 = atoi(lista.at(POS_Y2_LL).c_str());
	Linea* linea_izquierda = new Linea(pos_x1, pos_y1, pos_x2, pos_y2);			//Crea la linea
	return linea_izquierda;
}

/*
 * @name getSecurityToken
 * @param void
 * @Return
 * - SecurityToken* (un puntero al objeto SecurityToken)
 * @Descrition
 * Este Metodo se encarga de buscar dentro del archivo de texto de configuracion de la aplicacion (config.txt)
 * el identificador TOKEN para encontrar los valores asiganados al security token como lo son el username y el
 * password, Ademas se crea el objeto securitytoken que contiene dicha informacion. En caso de no encontrar los
 * valores del security token en el archivo returna nulo.
 */
SecurityToken* FileReader::getSecurityToken()
{
	string valor_buscado = buscarValor(ID_SECURITY_TOKEN);
	vector<string> lista = splitString(valor_buscado, SEPARATOR_SPECIAL);		//Divide el valor buscado segun , para encontrar los 2 valores del Security Token

	if(lista.size() != SIZE_TOKEN)												//Verifica que se haya encontrado los 2 valores del security Token
	{
		return NULL;															//Returna nulo porque no se encontraron todos los valores buscados
	}

	string username = lista[POS_USER_TOKEN];
	string password = lista[POS_PASS_TOKEN];
	SecurityToken* token = new SecurityToken(username, password);				//Crea el security token con los valores encontrados
	return token;
}

/*
 * @name getCodigoDispositivo
 * @param void
 * @Return
 * - string* (un puntero al string con el codigo del dispositivo)
 * @Descrition
 * Este Metodo se encarga de buscar dentro del archivo de texto de configuracion de la aplicacion (config.txt)
 * el identificador CODE para encontrar el valor asignado al mismo, que corresponde al codigo del embebido. En
 * caso de no encontrar dicho valor retorna un valor de nulo.
 */
string* FileReader::getCodigoDispositivo()
{
	string* codigo = new string();
	*codigo = buscarValor(ID_EMBEDDED_CODE);
	if(codigo->size() == 0)
	{
		delete codigo;	//Elimina el objeto
		return NULL;
	}
	return codigo;
}

/*
 *********************************************************************************
 *                                 Metodos                                       *
 *********************************************************************************
 */

/*
 * @name esNumero
 * @param
 * - rString : string (string que se desea convertir a entero entero)
 * @Return
 * - bool
 * @Descrition
 * Trata de convertir un string (rString) a un numero entero, en caso de poder realizar dicha operacion
 * se retorna un valor booleano de verdadero en caso contrario un valor de falso.
 *
 */
bool FileReader::esNumero(string rString)
{
	try
	{
		atoi(rString.c_str());
		return true;
	}
	catch(int exception)
	{
		//cout << "Error al convertir a entero el string: "<<rString<<" excepcion No."<< exception <<endl;
		return false;
	}
}

/*
 * @name buscarValor
 * @param
 * - rIdentificador : string (string que sera buscado dentro del archivo de texto)
 * @return
 * - string (string que corresponde al valor que contiene el identificador dentro del archivo de texto)
 * @Descrition
 * Buscar un valor o identificador dentro del archivo de configuracion de la aplicacion (config.txt)
 * luego de buscar dicho identificador procede a determinar el valor asignado a dicho identificador
 * y lo retorna como resultado. En caso de no encontrar el identificador o su valor returna un string vacio.
 */
string FileReader::buscarValor(string rIdentificador)
{
	string line;						//String que funcionara como buffer de lectura del archivo de texto
	string valor_buscado;				//String que contendra el valor correspondiente al identificador
	ifstream file(FILE_NAME.c_str());	//Descriptor del archivo para lectura

	cout << "Abriendo archivo..." << endl;
	if(!file.is_open())													//Verifica que el archivo se haya abierto
	{
		cout << "Error: Archivo de configuracion no encontrado" << endl;
		return valor_buscado;
	}

	cout << "Iniciando Lectura de Archivo..." << endl;

	while (getline(file,line))											//Obtiene una linea del archivo
	{
		cout <<line << endl;
		if(line[0] != COMMENT)											//Verifica que la linea no sea un comentario
		{
			vector<string> lista = splitString(line, SEPARATOR_NORMAL);	//Separa la linea en una lista de strings dado un delimitador
			if(lista.size() == 2)										//Verifica que el vector contenga 2 vectores, ejemplo ROI=12 [ROI,12]
			{
				if(lista.at(0).compare(rIdentificador) == 0)
				{
					valor_buscado = lista.at(1);
					break;
				}
			}
		}
	}
	cout << "Finalizada Lectura de Archivo..." << endl;
	file.close();	//Cierra el descriptor del archivo
	return valor_buscado;
}

/*
 * @name spliString
 * @param
 * - rString : string (string a ser dividido o separado)
 * - rDelimiter : string (string delimitador para realizar la particion o division)
 * @Descrition
 * Este Metodo se encarga de dividir un string (rString) en diversas partes segun un delimitador (rDelimiter),
 * y devuelve como resultado un vector de strings que contiene las partes en las que se dividio o separo el
 * string.
 */
vector<string> FileReader::splitString(string rString, string rDelimiter)
{
	vector<string> lista_elementos;
	string palabra = rString;
	while(palabra.size() != 0)
	{
		int pos_string = palabra.find(rDelimiter);
		if(pos_string == -1)
		{
			lista_elementos.push_back(palabra);
			break;
		}
		string elemento = palabra.substr(0,pos_string);
		if(elemento.size() != 0)
		{
			lista_elementos.push_back(elemento);
		}
		palabra = palabra.substr(pos_string+rDelimiter.size(), palabra.size());
	}
	return lista_elementos;
}
