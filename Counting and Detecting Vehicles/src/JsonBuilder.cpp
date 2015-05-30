/*
 * JsonBuilder.cpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 */

#include "JsonBuilder.hpp"

//Bibliotecas
#include "ConstantesJSON.hpp"	//Constantes para JSON

/*
 *********************************************************************************
 *                           Constructor y Destructor                            *
 *********************************************************************************
 */

JsonBuilder::JsonBuilder()
{
	//Constructor
	mStringBuffer = new ostringstream();	//Crea el string buffer para conversiones numericas
}

JsonBuilder::~JsonBuilder()
{
	//Destructor
	delete mStringBuffer;					//Destruye el string buffer
}

/*
 *********************************************************************************
 *                                 Metodos                                       *
 *********************************************************************************
 */

/*
 * @name convertToJSON
 * @param
 * - rReporte : Reporte (Objeto a ser convertido a uno del tipo JSON)
 * @return
 * - string (string en formato JSON del objeto)
 * @Descrition
 * Metodo encargado de convertir un objeto del tipo Reporte a un string que representa a dicho
 * objeto segun el estandar JSON.
 */
string JsonBuilder::convertToJSON(Reporte rReporte)
{
	string json_object_string;	//String que representa al objeto en formato JSON

	string json_codigo_string = convertString(rReporte.getCodigoDispositivo());	//Convierte el codigo del dispositivo a json
	string json_fecha_inicio = convertDate(rReporte.getFechaInicioReporte());	//Convierte la fecha de inicio a json
	string json_fecha_final  = convertDate(rReporte.getFechaFinalReporte());	//Convierte la fecha final a json
	string json_humedad_string = convertFloat(rReporte.getHumedad());			//Convierte la humedad a json
	string json_temperatura_string = convertFloat(rReporte.getTemperatura());	//Convierte la temperatura a json
	string json_luminosidad_string = convertFloat(rReporte.getLuminosidad());	//Convierte la luminosidad a json
	string json_token_string = convertToJSON(rReporte.getSecurityToken());		//Convierte el securitytoken a json
	string json_array_registros = convertArray(rReporte.getRegistros());		//Convierte la lista de registros a json

	//Formato ejemplo {"CodigoDispositivo":"AABB123","FechaInicio":1432791982246,
	//                 "FechaFinal":1432791982246,"Humedad":1.0,"Temperatura":40.0,
	//                 "Luminosidad":40.8,"Token":{"Username":"Juan","Password":"1234"},
	//                 "Registros":[{"FechaRegistro":1432791982246","Placa":"ABC123","VelocidadPromedio":4.5,"TipoVehiculo":"Liviano"},
	//				   {"FechaRegistro":1432791982246","Placa":"ABC123","VelocidadPromedio":4.5,"TipoVehiculo":"Liviano"}]}

	json_object_string += OBJETO_INI;														//Agrega el indicador de objeto inicial {
	json_object_string += REPORTE_CODIGO+ATRIBUTO_DECLARADOR+json_codigo_string;			//Agrega el atributo codigo de dispositivo
	json_object_string += ATRIBUTO_SEPARADOR;												//Agrega un separador de atributo ,
	json_object_string += REPORTE_FECHA_INICIO+ATRIBUTO_DECLARADOR+json_fecha_inicio;		//Agrega el atributo fecha inicial
	json_object_string += ATRIBUTO_SEPARADOR;												//Agrega un separador de atributo ,
	json_object_string += REPORTE_FECHA_FINAL+ATRIBUTO_DECLARADOR+json_fecha_final;			//Agrega el atributo fecha final
	json_object_string += ATRIBUTO_SEPARADOR;												//Agrega un separador de atributo ,
	json_object_string += REPORTE_HUMEDAD+ATRIBUTO_DECLARADOR+json_humedad_string;			//Agrega el atributo humedad
	json_object_string += ATRIBUTO_SEPARADOR;												//Agrega un separador de atributo ,
	json_object_string += REPORTE_TEMPERATURA+ATRIBUTO_DECLARADOR+json_temperatura_string;	//Agrega el atributo temperatura
	json_object_string += ATRIBUTO_SEPARADOR;												//Agrega un separador de atributo ,
	json_object_string += REPORTE_LUMINOSIDAD+ATRIBUTO_DECLARADOR+json_luminosidad_string;	//Agrega el atributo luminosidad
	json_object_string += ATRIBUTO_SEPARADOR;												//Agrega un separador de atributo ,
	json_object_string += REPORTE_SECURITYTOKEN+ATRIBUTO_DECLARADOR+json_token_string;		//Agrega el atributo securitytoken
	json_object_string += ATRIBUTO_SEPARADOR;												//Agrega un separador de atributo ,
	json_object_string += REPORTE_REGISTROS+ATRIBUTO_DECLARADOR+json_array_registros;		//Agrega la lista de registros
	json_object_string += OBJETO_FIN;														//Agrega el indicador de objeto final }

	return json_object_string;
}

/*
 * @name convertToJSON
 * @param
 * - rRegistro : RegistroVehiculo (Objeto a ser convertido a un del tipo JSON)
 * @return
 * - string (string en formato JSON del objeto)
 * @Descrition
 * Metodo encargado de convertir un objeto del tipo RegistroVehiculo a un string que representa
 * a dicho objeto segun el estandar JSON.
 */
string JsonBuilder::convertToJSON(RegistroVehiculo rRegistro)
{
	string json_object_string;	//String que representa al objeto en formato JSON

	string json_fecha_string = convertDate(rRegistro.getFecha());					//Convierte la fecha a json
	string json_placa_string = convertString(rRegistro.getPlaca());					//Convierte la placa a json
	string json_velocidad_string = convertFloat(rRegistro.getVelocidadPromedio());	//Convierte la velocidad a json
	string json_tipo_string = convertString(rRegistro.getTipoVehiculo());			//Convierte el tipo a json

	//Formato ejemplo {"FechaRegistro":1432791982246","Placa":"ABC123","VelocidadPromedio":4.5,"TipoVehiculo":"Liviano"}

	json_object_string += OBJETO_INI;													//Agrega el indicador de objeto inicial {
	json_object_string += REGISTRO_FECHA+ATRIBUTO_DECLARADOR+json_fecha_string;			//Agrega el atributo fecha
	json_object_string += ATRIBUTO_SEPARADOR;											//Agrega un separador de atributo ,
	json_object_string += REGISTRO_PLACA+ATRIBUTO_DECLARADOR+json_placa_string;			//Agrega el atributo placa
	json_object_string += ATRIBUTO_SEPARADOR;											//Agrega un separador de atributo ,
	json_object_string += REGISTRO_VELOCIDAD+ATRIBUTO_DECLARADOR+json_velocidad_string;	//Agrega el atributo velocidad
	json_object_string += ATRIBUTO_SEPARADOR;											//Agrega un separador de atributo ,
	json_object_string += REGISTRO_TIPO+ATRIBUTO_DECLARADOR+json_tipo_string;			//Agrega el atributo tipo
	json_object_string += OBJETO_FIN;													//Agrega el indicador de objeto final }

	return json_object_string;
}

/*
 * @name convertToJSON
 * @param
 * - rToken : SecurityToken (Objeto a ser convertido a uno del tipo JSON)
 * @return
 * - string (string en formato JSON del objeto)
 * @Descrition
 * Metodo encargado de convertir un objeto del tipo SecurityToken a un string que representa
 * a dicho objeto segun el estandar JSON.
 */
string JsonBuilder::convertToJSON(SecurityToken rToken)
{
	string json_object_string;	//String que representa al objeto en formato JSON
	string json_username = convertString(rToken.getUsername());	//Convierte el username al formato JSON para string
	string json_password = convertString(rToken.getPassword());	//Convierte el password al formato JSON para string

	//Formato ejemplo {"Username":"Juan","Password":"1234"}

	json_object_string += OBJETO_INI;										//Agrega el indicador de objeto inicial {
	json_object_string += TOKEN_USERNAME+ATRIBUTO_DECLARADOR+json_username;	//Agrega el atributo username
	json_object_string += ATRIBUTO_SEPARADOR;								//Agrega un separador de atributo ,
	json_object_string += TOKEN_PASSWORD+ATRIBUTO_DECLARADOR+json_password;	//Agrega el atributo password
	json_object_string += OBJETO_FIN;										//Agrega el indicador de objeto final }

	return json_object_string;
}

/*
 * @name convertirFloat
 * @param
 * - rValor : float (valor float a ser convertirdo a string del tipo JSON)
 * @return
 * - string (float en version estandar de JSON)
 * @Descrition
 * Metodo encargado de convertir un valor float en un string cuyo formato sea el establecido
 * por JSON para valores de punto de flotante.
 */
string JsonBuilder::convertFloat(float rValor)
{
	*mStringBuffer<<rValor;					//Almacena el float en el buffer
	string result = mStringBuffer->str();	//Convierte el buffer en string

	mStringBuffer->str("");					//Limpia el buffer
	mStringBuffer->clear();					//Limpia el buffer

	if(result.find(FLOAT_PUNTO) == string::npos)	//Verifica que tenga un punto
	{
		result = result+FLOAT_CERO_END;				//Agrega un punto y 0 en caso para que sea distinto a un entero
	}
	return result;
}

/*
 * @name convertirInt
 * @param
 * - rValor : int (valor entero a ser convertirdo a string del tipo JSON)
 * @return
 * - string (int en version estandar de JSON)
 * @Descrition
 * Metodo encargado de convertir un valor entero en un string cuyo formato sea el establecido por JSON para Int.
 */
string JsonBuilder::convertInt(int rValor)
{
	*mStringBuffer<<rValor;					//Almacena el entero en el buffer
	string result = mStringBuffer->str();	//Convierte el buffer en string

	mStringBuffer->str("");					//Limpia el buffer
	mStringBuffer->clear();					//Limpia el buffer

	return result;
}

/*
 * @name convertirString
 * @param
 * - rPalabra : string (string a ser convertido a un string con el formato JSON)
 * @return
 * - string (string en version estandar de JSON)
 * @Descrition
 * Metodo encargado de convertir un string en otro string pero con el formato JSON.
 */
string JsonBuilder::convertString(string rPalabra)
{
	string json_string = ATRIBUTO_COMILLA+rPalabra+ATRIBUTO_COMILLA; 	//Crea el string en formato JSON
	return json_string;
}

/*
 * @name convertirDate
 * @param
 * - rFecha : time_t (fecha a ser convertida al establecido por JSON)
 * @return
 * - string (string que contiene la fecha en el formato JSON)
 * @Descrition
 * Metodo encargado de convertir un time_t (Fecha) en un timestamp establecido por el estandar de JSON.
 */
string JsonBuilder::convertDate(time_t rFecha)
{
	char buffer[30];
	strftime(buffer,30,DATE_FORMAT_JSON.c_str(),localtime(&rFecha));	//Convierte la fecha al formato JSON para date (year-month-dayThour:minutes:seconds-TIMEZONE

	*mStringBuffer<<buffer;					//Almacena el entero en el buffer
	string result = mStringBuffer->str();	//Convierte el buffer en string

	mStringBuffer->str("");					//Limpia el buffer
	mStringBuffer->clear();					//Limpia el buffer

	return result;
}

/*
 * @name convertArray
 * @param
 * - rRegistros : vector<RegistroVehiculo> (lista de registros)
 * @return
 * - string (string que contiene la representacion en formato JSON de la lista de registros)
 * @Descrition
 * Metodo encargado de convertir una lista de objetos RegistroVehiculo en un objeto con formato JSON
 * que represente a dicha lista.
 */
string JsonBuilder::convertArray(vector<RegistroVehiculo> rRegistros)
{
	string json_object_array;	//String que representa la lista en formato JSON

	//Formato Ejemplo [{"fecha":1432509252,"placa":"ABC123","velocidad":0.0,"tipo":"Liviano"},
	// 				   {"fecha":1432509252,"placa":"123ABC","velocidad":4.0,"tipo":"Liviano"}]

	json_object_array += LISTA_INI;								//Agrega el indicador de lista inicial [

	for(unsigned int indice=0; indice < rRegistros.size(); indice++)
	{
		RegistroVehiculo registro = rRegistros[indice];
		string json_registro_object = convertToJSON(registro);	//Convierte el registro a un objeto JSON
		json_object_array += json_registro_object;				//Agrega el objeto JSON al string
		if(indice+1 != rRegistros.size())						//verifica que no sea el ultimo elemento
		{
			json_object_array += LISTA_SEPARADOR;				//Agrega un separador de lista ,
		}
	}

	json_object_array += LISTA_FIN;								//Agrega el indicador de lista final ]
	return json_object_array;
}

