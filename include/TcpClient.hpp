/*
 * @file 		TcpClient.hpp
 * @version 	1.0
 * @author 		Alonso Loaiza Pereira
 * @e-mail		aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 *
 * @description
 * 		This class is a implementation of a tcp client which allows to established a connection with a host (server) by TCP protocol.
 * 		Implements the classic functions like connect to the host, receive a message, send a message and a function to close the connection.
 */

#ifndef TCPCLIENT_HPP_
#define TCPCLIENT_HPP_

//Libraries
#include <string>		/* string object */
#include <arpa/inet.h>	/* struct sockaddr_in, blind, listen, etc */
#include <errno.h>		/* errno, EAFNOSUPPORT */
#include <string.h>		/* memset function */
#include <unistd.h>		/* close function */
#include <fcntl.h> 		/* fcntl, and constants*/

//Classes specified by namespace
using std::string;

namespace TCP_IP
{
	class TcpClient {
	public:
		//Constructor and Destructor
		TcpClient();
		virtual ~TcpClient();

		//Methods
		bool connect(const string &rHost,  const int &rPort);
		bool send(const string &rMessage);
		bool recv(string &rReponse);
		void setNonBlocking(const bool rState);
		void closeConnection();

	private:
		//Attributes
		int mSockfd;		//Socket file descriptor
		sockaddr_in mAddr;	//Struct for handling Internet access

		//Methods
		bool createSocket();
	};

} /* namespace TCP_IP */

#endif /* TCPCLIENT_HPP_ */
