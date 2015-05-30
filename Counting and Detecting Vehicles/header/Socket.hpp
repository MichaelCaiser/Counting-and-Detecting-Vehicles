// Definition of the Socket class

#ifndef SOCKET_HPP_
#define SOCKET_HPP_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>

#include <string.h>
#include <errno.h>
#include <fcntl.h>

#include <iostream>
using namespace std;

const int MAXHOSTNAME = 200;
const int MAXCONNECTIONS = 5;
const int MAXRECV = 500;

class Socket
{
public:
	Socket();
	virtual ~Socket();

	// Server initialization
	bool create();
	bool bind ( const int port );
	bool listen() const;
	bool accept ( Socket& ) const;

	// Client initialization
	bool connect ( const std::string host, const int port );

	// Data Transimission
	bool send ( const std::string ) const;
	int recv ( std::string& ) const;


	void set_non_blocking ( const bool );
	bool is_valid() const { return m_sock != -1; }

	//Close socket
	void closeSocket();

private:

	int m_sock;
	sockaddr_in m_addr;
};

#endif	/* SOCKET_HPP_ */
