/*
 * WebServiceConnection.cpp
 *
 * @Author: Alonso Loaiza Pereira
 * @e-mail: hiyitsu@gmail.com
 * @University: Instituto Tecnologico de Costa Rica (TEC)
 */

#include "WebServiceConnection.hpp"

#include <iostream>
using std::cout;
using std::endl;

/*
 *********************************************************************************
 *                           Constructor y Destructor                            *
 *********************************************************************************
 */

WebServiceConnection::WebServiceConnection()
{
	//Constructor
	//Inicializa los objetos
	mpSocket = new Socket();
	mpJsonBuilder = new JsonBuilder();
	mpRequestBuilder = new HttpRequestBuilder();
	mpConnectionConfig = new ConnectionConfiguration();
}

WebServiceConnection::~WebServiceConnection() {
	//Destructor
	//Libera la memoria
	delete mpSocket;
	delete mpJsonBuilder;
	delete mpRequestBuilder;
	delete mpConnectionConfig;
}

/*
 *********************************************************************************
 *                                 Setters                                       *
 *********************************************************************************
 */

void WebServiceConnection::setConnectionConfiguration(ConnectionConfiguration rConfig)
{
	*mpConnectionConfig = rConfig;
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
 * Este Metodo se encarga de dividir un string (rString) en diversas partes segun un delimitador (rDelimiter),
 * y devuelve como resultado un vector de strings que contiene las partes en las que se dividio o separo el
 * string.
 */
void WebServiceConnection::save(Reporte rReporte)
{
	bool is_connect = connect();
	if(is_connect)
	{
		string response;
		string host = mpConnectionConfig->getHost();
		int port = mpConnectionConfig->getPort();
		string url_post = mpConnectionConfig->getUrlPostReport();
		string report_json = mpJsonBuilder->convertToJSON(rReporte);											//Crea el objeto JSON del reporte
		cout<<report_json<<endl;
		string http_request = mpRequestBuilder->createHttpPostReportRequest(host,port,url_post,report_json);	//Crea la solicitud HTTP para el webservice

		if(!mpSocket->send(http_request))					//Verifica si no se envio el mensaje
		{
			cout<<"Error: cant send the message"<<endl;
			goto FINAL;
		}

		if(!mpSocket->recv(response))						//Verifica si se recibio un mensaje
		{
			cout<<"Error: cant recv the message"<<endl;
			goto FINAL;
		}

		if(!mpRequestBuilder->isHttpResponseOK(response))	//Verifica si el mensaje recibido es del tipo OK
		{
			cout<<"Error: HTTP response isn't OK"<<endl;
			goto FINAL;
		}

		cout<<response<<endl;			//remover
		FINAL:
		mpSocket->closeSocket();		//Cierra el Socket
		return;
	}
}

/*
 * @name connect
 * @param
 * @return
 * - bool : indicando si se pudo connectar el socket al puerto y host establecidos
 * @Descrition
 * Este metodo se encarga crear el socket y se intenta conectar a un host y puerto establecido,
 * en caso que se conecte se retorna un valor de verdad.
 */
bool WebServiceConnection::connect()
{
	if(!mpSocket->create())
	{
		cout<<"Error: cant create the socket"<<endl;
		return false;
	}
	if(!mpSocket->connect(mpConnectionConfig->getHost(),mpConnectionConfig->getPort()))
	{
		cout<<"Error: cant connect to the server"<<endl;
		return false;
	}
	return true;
}


