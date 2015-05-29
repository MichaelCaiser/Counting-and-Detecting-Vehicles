/*
 * HttpRequestBuilder.cpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 */

#include "HttpRequestBuilder.hpp"

//Bibliotecas
#include "ConstantesHTTP.hpp"	//Constantes para el formato HTTP

/*
 *********************************************************************************
 *                           Constructor y Destructor                            *
 *********************************************************************************
 */

HttpRequestBuilder::HttpRequestBuilder() {
	//Constructor
	mStringBuffer = new ostringstream();	//Crea el string buffer para conversiones numericas

}

HttpRequestBuilder::~HttpRequestBuilder() {
	//Destructor
	delete mStringBuffer;					//Destruye el string buffer
}

/*
 *********************************************************************************
 *                                 Metodos                                       *
 *********************************************************************************
 */

/*
 * @name createHttpPostReportRequest
 * @param
 * - rHost : string (Direccion IP a la cual se desea enviar la consulta)
 * - rPort : int    (Puerto a traves del cual se envia la solicitud HTTP)
 * - rUrl  : string (Direccion del recurso al cual se esta accediendo (webservice url))
 * - rBody : string (Contenido a ser enviado (objeto JSON))
 * @return
 * - string (Con formato HTTP de la solicitud de POST un reporte en el webservice)
 * @Descrition
 * Se crea un string con el formato HTTP para realizar un post de la informacion de un
 * reporte en el webservice (con tecnología RESTfull). Para ello se requiere la direccion
 * del host, el puerto asi como el url del webservice y el contenido a ser enviado (body).
 */
string HttpRequestBuilder::createHttpPostReportRequest(string rHost, int rPort, string rUrl, string rBody)
{
	string http_request;					//String donde se almacena la consulta HTTP

	//Estructura del request
	string http_header;						//Encabezado de la consulta HTTP
	string http_body = rBody;				//Cuerpo de la consulta HTTP

	int body_length = http_body.size();		//Tamano en bytes del cuerpo

	//Crea la estructura del encabezado

	//ejemplo POST http://localhost:8080/RestExample/addEmployee HTTP/1.1
	http_header += HTTP_METHOD_POST+HTTP_SPACE+rUrl+HTTP_SPACE+HTTP_VERSION_1_1;	//Agrega la direccion del recurso
	http_header += HTTP_NEW_LINE;													//Agrega un salto de linea

	//ejemplo Host: localhost:8080
	http_header += HTTP_HOST+rHost+HTTP_HOST_PORT_SEPARATOR+convertIntToString(rPort);	//Agrega el host
	http_header += HTTP_NEW_LINE;														//Agrega un salto de linea

	//ejemplo Content-Type: application/json; charset=utf-8
	http_header += HTTP_CONTENT_TYPE_JSON+HTTP_SPACE+HTTP_CHARSET_UTF;		//Agrega el tipo de contenido del post
	http_header += HTTP_NEW_LINE;											//Agrega un salto de linea

	//ejemplo Content-Length: 166
	http_header += HTTP_CONTENT_LENGTH+convertIntToString(body_length);		//Agrega el largo del largo del body
	http_header += HTTP_NEW_LINE;											//Agrega un salto de linea


	//Crea el http_request
	http_request += http_header;	//Agrega el encabezado
	http_request += HTTP_NEW_LINE;	//Agrega un salto de linea para separar el encabezado del cuerpo
	http_request += http_body;		//Agrega el cuerpo

	return http_request;
}

/*
 * @name convertIntToString
 * @param
 * - rValue : int (valor entero que se desea convertir a string)
 * @return
 * - string (Corresponde al valor entero)
 * @Descrition
 * Metodo encargado de convertir un valor entero a un string
 */
string HttpRequestBuilder::convertIntToString(int rValue)
{
	*mStringBuffer<<rValue;					//Almacena el entero en el buffer
	string result = mStringBuffer->str();	//Convierte el buffer en string

	mStringBuffer->str("");					//Limpia el buffer
	mStringBuffer->clear();					//Limpia el buffer

	return result;
}

