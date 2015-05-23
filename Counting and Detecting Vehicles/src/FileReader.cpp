/*
 * FileReader.cpp
 *
 * Author: Alonso Loaiza Pereira
 * e-mail: hiyitsu@gmail.com
 * University: Instituto Tecnologico de Costa Rica (TEC)
 */

#include "FileReader.hpp"

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

ConfiguracionConexion* FileReader::getConfiguracionConexion()
{
	return NULL;
}

ConfiguracionEmpotrado* FileReader::getConfiguracionDispositivo()
{
	return NULL;
}

/*
 * @name getROI
 * @param void
 * @Descrition
 * 		Este Metodo se encarga de buscar dentro del archivo de texto de configuracion de la aplicacion (config.txt)
 * 		el identificador de ROI para encontrar el valor asignado a la region de interes (ROI) tanto como su posicion,
 * 		tamano y altura. Ademas se crea el objeto Region que contiene la informacion de la ROI y retorna un puntero
 * 		del mismo objeto.
 */
Region* FileReader::getROI()
{
	string valor_buscado = buscarValor(ID_ROI);

	vector<string>* lista = splitString(valor_buscado, SEPARATOR_SPECIAL);	//Divide el valor buscado segun , para encontrar los 4 valores del ROI
	if(lista->size() != SIZE_ROI)													//Verifica que se haya encontrado los 4 valores de la ROI
	{
		return NULL;														//Retorna nulo indicando el valor buscado no es correcto
	}

	if(!esNumero(lista->at(POS_X_ROI)) || !esNumero(lista->at(POS_Y_ROI)) ||
	   !esNumero(lista->at(POS_ANCHO_ROI)) ||!esNumero(lista->at(POS_ALTO_ROI)))	//Verifica que los valores de la lista sean numeros enteros
	{
		return NULL;																//Retorna nulo indicando que los valores buscados no son numeros enteros
	}

	//Convierte los strings del vector a numeros
	int posicion_x = atoi(lista->at(POS_X_ROI).c_str());
	int posicion_y = atoi(lista->at(POS_Y_ROI).c_str());
	int ancho = atoi(lista->at(POS_ANCHO_ROI).c_str());
	int alto = atoi(lista->at(POS_ALTO_ROI).c_str());

	delete lista; //Libera la memoria asignada al vector de strings

	Region* roi = new Region(posicion_x, posicion_y, ancho, alto);			//Crea la region
	return roi;
}

/*
 * @name getLineaDerecha
 * @param void
 * @Descrition
 * 		Este Metodo se encarga de buscar dentro del archivo de texto de configuracion de la aplicacion (config.txt)
 * 		el identificador RL para encontrar los valores asiganados a la linea derecha como lo son los dos puntos
 * 		que determinan a la recta. Ademas se crea el objeto Linea que contiene la informacion de dicha linea.
 */
Linea* FileReader::getLineaDerecha()
{
	string valor_buscado = buscarValor(ID_LEFT_LINE);

	vector<string>* lista = splitString(valor_buscado, SEPARATOR_SPECIAL);	//Divide el valor buscado segun , para encontrar los 4 valores de la linea derecha
	if(lista->size() != SIZE_LL)													//Verifica que se haya encontrado los 4 valores de la ROI
	{
		return NULL;																//Retorna nulo indicando el valor buscado no es correcto
	}

	if(!esNumero(lista->at(POS_X1_LL)) || !esNumero(lista->at(POS_Y1_LL)) ||
	   !esNumero(lista->at(POS_X2_LL)) ||!esNumero(lista->at(POS_Y2_LL)))		//Verifica que los valores de la lista sean numeros enteros
	{
		return NULL;															//Retorna nulo indicando que los valores buscados no son numeros enteros
	}

	//Convierte los strings del vector a numeros
	int pos_x1 = atoi(lista->at(POS_X1_LL).c_str());
	int pos_y1 = atoi(lista->at(POS_Y1_LL).c_str());
	int pos_x2 = atoi(lista->at(POS_X2_LL).c_str());
	int pos_y2 = atoi(lista->at(POS_Y2_LL).c_str());

	delete lista; //Libera la memoria asignada al vector de strings

	Linea* linea_izquierda = new Linea(pos_x1, pos_y1, pos_x2, pos_y2);			//Crea la linea
	return linea_izquierda;
}

/*
 * @name getLineaIzquierda
 * @param void
 * @Descrition
 * 		Este Metodo se encarga de buscar dentro del archivo de texto de configuracion de la aplicacion (config.txt)
 * 		el identificador LL para encontrar los valores asiganados a la linea izquierda como lo son los dos puntos
 * 		que determinan a la recta. Ademas se crea el objeto Linea que contiene la informacion de dicha linea.
 */
Linea* FileReader::getLineaIzquierda()
{
	string valor_buscado = buscarValor(ID_RIGH_LINE);

	vector<string>* lista = splitString(valor_buscado, SEPARATOR_SPECIAL);	//Divide el valor buscado segun , para encontrar los 4 valores de la linea derecha
	if(lista->size() != SIZE_RL)													//Verifica que se haya encontrado los 4 valores de la ROI
	{
		return NULL;																//Retorna nulo indicando el valor buscado no es correcto
	}

	if(!esNumero(lista->at(POS_X1_RL)) || !esNumero(lista->at(POS_Y1_RL)) ||
	   !esNumero(lista->at(POS_X2_RL)) ||!esNumero(lista->at(POS_Y2_RL)))		//Verifica que los valores de la lista sean numeros enteros
	{
		return NULL;															//Retorna nulo indicando que los valores buscados no son numeros enteros
	}

	//Convierte los strings del vector a numeros
	int pos_x1 = atoi(lista->at(POS_X1_RL).c_str());
	int pos_y1 = atoi(lista->at(POS_Y1_RL).c_str());
	int pos_x2 = atoi(lista->at(POS_X2_RL).c_str());
	int pos_y2 = atoi(lista->at(POS_Y2_RL).c_str());

	delete lista; //Libera la memoria asignada al vector de strings

	Linea* linea_derecha = new Linea(pos_x1, pos_y1, pos_x2, pos_y2);			//Crea la linea
	return linea_derecha;
}

/*
 *********************************************************************************
 *                                 Metodos                                       *
 *********************************************************************************
 */

/*
 * @name spliString
 * @param
 * - rString : string (string a ser dividido o separado)
 * - rDelimiter : string (string delimitador para realizar la particion o division)
 * @Descrition
 * 		Este Metodo se encarga de dividir un string (rString) en diversas partes segun un
 * 		delimitador (rDelimiter), y devuelve como resultado un puntero a un vector de strings
 * 		que contiene las partes en las que se dividio o separo el string.
 */
vector<string>* FileReader::splitString(string rString, string rDelimiter)
{
	vector<string>* lista_elementos = new vector<string>();
	string palabra = rString;
	while(palabra.size() != 0)
	{
		int pos_string = palabra.find(rDelimiter);
		if(pos_string == -1)
		{
			lista_elementos->push_back(palabra);
			break;
		}
		string elemento = palabra.substr(0,pos_string);
		if(elemento.size() != 0)
		{
			lista_elementos->push_back(elemento);
		}
		palabra = palabra.substr(pos_string+rDelimiter.size(), palabra.size());
	}
	return lista_elementos;
}

/*
 * @name esNumero
 * @param
 * - rString : string (string que sera convertido a entero)
 * @Descrition
 * 		Este Metodo se encarga de tratar de convertir un string (rString) a un numero entero, en caso de poder
 * 		realizar dicha operacion se retorna un valor booleano de verdadero en caso contrario un valor de falso.
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
		cout << "Error al convertir a entero el string: "<<rString<<" excepcion No."<< exception <<endl;
		return false;
	}
}

/*
 * @name buscarValor
 * @param
 * - rIdentificador : string (string que sera buscado dentro del archivo de texto)
 * @Descrition
 * 		Este Metodo se encarga buscar un valor o identificador dentro del archivo de configuracion de la aplicacion
 * 		(config.txt) luego de buscar dicho identificador procede a determinar el valor asignado a dicho identificador
 * 		y lo retorna como resultado.
 */
string FileReader::buscarValor(string rIdentificador)
{
	string* line = new string();						//String que funcionara como buffer de lectura del archivo de texto
	ifstream* file = new ifstream(FILE_NAME.c_str());	//Crea un descriptor del archivo para lectura

	cout << "Abriendo archivo..." << endl;
	if(!file->is_open())													//Verifica que el archivo se haya abierto
	{
		cout << "Error: Archivo de configuracion no encontrado" << endl;
		return NULL;
	}

	cout << "Iniciando Lectura de Archivo..." << endl;
	string valor_buscado;
	while (getline(*file,*line))											//Obtiene una linea del archivo
	{
		cout << *line << '\n';
		if((*line)[0] != COMMENT)											//Verifica que la linea no sea un comentario
		{
			vector<string>* lista = splitString(*line, SEPARATOR_NORMAL);	//Separa la linea en una lista de strings dado un delimitador
			if(lista->size() == 2)											//Verifica que el vector contenga 2 vectores, ejemplo ROI=12 [ROI,12]
			{
				if(lista->at(0).compare(rIdentificador) == 0)
				{
					valor_buscado = lista->at(1);
					break;
				}
			}
			delete lista;	//Libera la memoria asignada al arreglo de strings
		}
	}
	cout << "Finalizada Lectura de Archivo..." << endl;
	file->close();	//Cierra el descriptor del archivo
	delete line;	//Libera la memoria del string buffer de lectura de linea
	delete file;	//Libera la memoria del archivo descriptor
	return valor_buscado;
}

