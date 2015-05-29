/*
 * ConstantesHTTP.hpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 *
 * @Description:
 * Header que incluye la definicion de constantes para la elaboracion de un request
 * a traves del protocolo HTTP.
 */

#ifndef CONSTANTESHTTP_HPP_
#define CONSTANTESHTTP_HPP_

//Bibliotecas
#include <string>
using std::string;

/**
 * Constantes de un Encabezado HTTP
 */

//HTTP Tipos de Metodo
const string HTTP_METHOD_POST = "POST";
const string HTTP_METHOD_GET = "GET";

//HTTP Version
const string HTTP_VERSION_1_1 = "HTTP/1.1";

//HTTP Host
const string HTTP_HOST = "Host: ";
const string HTTP_HOST_PORT_SEPARATOR = ":";

//HTTP Formato
const string HTTP_SPACE = " ";
const string HTTP_NEW_LINE = "\r\n";

//HTTP Content
const string HTTP_CONTENT_TYPE_JSON = "Content-Type: application/json;";
const string HTTP_CONTENT_LENGTH = "Content-Length: ";

//Http Charset
const string HTTP_CHARSET_UTF = "charset=utf-8";

#endif /* CONSTANTESHTTP_HPP_ */
