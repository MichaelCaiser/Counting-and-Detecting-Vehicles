/*
 * @file 		TcpClient.cpp
 * @version 	1.0
 * @author 		Alonso Loaiza Pereira
 * @e-mail		aloaizapereira@gmail.com
 * @university	Tecnológico de Costa Rica (TEC)
 */

#include "TcpClient.hpp"

//Library
#include <iostream>	/* cerr, endl */

//Classes specified by namespace
using std::cerr;
using std::endl;

const int MSG_MAX_LENGTH = 1000;

namespace TCP_IP {

TcpClient::TcpClient() {
	// TODO Auto-generated constructor stub
	mSockfd = -1;
}

TcpClient::~TcpClient() {
	//Check if the socket file descriptor still is connected to the host to close the connection.
	if(mSockfd != -1){
		::close(mSockfd);
	}
}

/**
 * This method tries to connect to the host by a specific port, if the connection can be established
 * returns true otherwise return false.<p>
 *
 * @param rHost		The host name to connect (Example localhost)
 * @param rPort		The port to connect (Example for internet port 80)
 * @return bool 	A boolean which indicates if the connection was established.
 */
bool TcpClient::connect(const string &rHost, const int &rPort){
	if(!createSocket()){
		return false;
	}
	mAddr.sin_family = AF_INET;
	mAddr.sin_port = htons(rPort);
	inet_pton(AF_INET, rHost.c_str(), &mAddr.sin_addr);
	if (errno == EAFNOSUPPORT) {
		cerr << "Error: Addr family not supported"<<endl;
		return false;
	}
	int status = ::connect(mSockfd,(sockaddr *) &mAddr,sizeof(mAddr));
	//Check if the socket could connect to the host.
	if(status != 0){
		return false;
	}
	return true;
}

/**
 * This method sends a message to the host by a specific port, if the message is sent successfully returns a
 * true value otherwise the method returns a false value.
 *
 * @param rMessage	The message that will be sent to the host by a specific port
 * @return bool		A boolean that represents if the message was sent successfully
 */
bool TcpClient::send(const string &rMessage){
	int status = ::send(mSockfd, rMessage.c_str(), rMessage.size(), MSG_NOSIGNAL );
	if(status == -1){
		cerr << "" << endl;
		return false;
	}
	return true;
}

/**
 * This method receives the response of the host to a request, and store the response in a
 * string (rResponse), if the response had been received successfully a true value will be returned
 * otherwise the method returns a false value.<p>
 *
 * @param rReponse 	The response of the host to a request.
 * @return bool		A boolean value which indicates if the response had been received.
 */
bool TcpClient::recv(string &rReponse){
	//buffer to receive the information sent by the host
	char msg_buffer[MSG_MAX_LENGTH + 1 ];
	rReponse = "";
	memset(msg_buffer, 0, MSG_MAX_LENGTH + 1);
	int status = ::recv(mSockfd, msg_buffer, MSG_MAX_LENGTH, 0 );
	if (status == -1){
		cerr << "Error: host's response cannot be received" << endl;
		return false;
	}
	else if(status == 0){
		cerr << "Error: the connection has been closed." << endl;
		return false;
	}
	else{
		rReponse = msg_buffer;
		return true;
	}
}

/**
 * This method sets the non blocking state of the tcp client. If the non blocking state is true
 * the client will not wait (it wait for a short time) for a response of the host otherwise
 * the client waits for a response of the host.
 * The tcp client is in a blocking state for default.<p>
 *
 * @param rState	The non blocking state that the tcp client will have.
 */
void TcpClient::setNonBlocking(const bool rState){
	//get the status flags of the socket file descriptor
	int flags = fcntl(mSockfd, F_GETFL);
	if(flags < 0){
		cerr << "Error: can't access the socket file descriptor flags." << endl;
		return;
	}

	//established the flags depending of the rState
	if(rState){
		flags = (flags | O_NONBLOCK);
	}
	else{
		flags = (flags & ~O_NONBLOCK);
	}

	//Set the flags
	fcntl(mSockfd,F_SETFL,flags);
}

/**
 * This method close the tcp connection to the host.
 */
void TcpClient::closeConnection(){
	if(mSockfd != -1){
		::close(mSockfd);
		mSockfd = -1;		//Represents a not assigned socket file descriptor
	}
}


/**
 * This method creates and sets the configuration of the socket and returns a true value if everything
 * is right, if some error happens returns a false value.
 *
 * @return bool		A boolean indicating if the socket was created correctly.
 */
bool TcpClient::createSocket(){
	//Create the socket
	mSockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(mSockfd == -1){
		cerr << "Error: couldn't create the socket." << endl;
		return false;
	}

	/**
	 * set the socket options
	 * visit http://pubs.opengroup.org/onlinepubs/7908799/xns/setsockopt.html to find more information.
	 */
	int on = 1;
	if ( setsockopt (mSockfd,SOL_SOCKET,SO_REUSEADDR,(const char*) &on,sizeof(on)) != 0 ){
		mSockfd = -1;
		cerr << "Error: couldn't set the socket options." << endl;
		return false;
	}
	return true;
}



} /* namespace TCP_IP */
