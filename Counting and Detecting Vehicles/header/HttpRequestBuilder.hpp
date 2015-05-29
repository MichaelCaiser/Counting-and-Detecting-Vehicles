/*
 * HttpRequestBuilder.hpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * @Description:
 * Clase encargada de generar un strings cuyo formato sea el de solicitudes HTTP en su
 * version 1.1
 */

#ifndef HTTPREQUESTBUILDER_HPP_
#define HTTPREQUESTBUILDER_HPP_

//Bibliotecas
#include <string>	//Biblioteca para la manipulacion de string
#include <sstream>	//Biblioteca para la conversion de valores numericos (float e int) string

//Especificacion de clases por namespace
using std::string;
using std::ostringstream;

class HttpRequestBuilder
{
public:

	//Constructor y Destructor
	HttpRequestBuilder();
	virtual ~HttpRequestBuilder();

	//Metodos
	string createHttpPostReportRequest(string rHost, int rPort, string rUrl, string rBody);

private:

	//Atributos
	ostringstream* mStringBuffer;	//String Buffer para conversion de valores numericos

	//Metodos
	string convertIntToString(int rValue);

};

#endif /* HTTPREQUESTBUILDER_HPP_ */
