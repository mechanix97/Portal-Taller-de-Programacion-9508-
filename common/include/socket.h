#ifndef _COMMON_SOCKET_H_
#define _COMMON_SOCKET_H_

#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <iostream>
#include <cstring>

#include "exceptions.h"

#define MAX_CONNECTIONS 10
#define ERROR -1

#define CLIENT_FAMILY AF_INET
#define CLIENT_SOCKTYPE SOCK_STREAM
#define CLIENT_FLAGS 0

#define SERVER_FAMILY AF_INET
#define SERVER_SOCKTYPE SOCK_STREAM
#define SERVER_FLAGS AI_PASSIVE

#define SERVER_NAME "127.0.0.1"

class Socket{
private:
	bool connected;
  	struct addrinfo *ptr;
  	int fileDescriptor;

public:
	Socket();
	explicit Socket(int fd);
	~Socket();

	int get() const;
	Socket &operator=(const Socket &other) = delete;
	Socket &operator=(Socket &other) = delete;
  	Socket(const Socket &other) = delete;
	Socket(Socket &other) = delete;
  	Socket(Socket &&other);
  	Socket& operator=(Socket &&other);
	void close();
	void setSocket(struct addrinfo *p);
	void connect(const std::string& hostName, const std::string& port);
	void bindSocket(struct addrinfo *p);
	void bindAndListen(const std::string& port);
	void shutdown(char mode);
	Socket accept();
	int receive(void * ptr, size_t len) const;
	int send(const void * ptr, size_t len) const;

private:
	void setClientHints(struct addrinfo *hints);
	void setServerHints(struct addrinfo *hints);
	void getServerAddrinfo(const char * port);
	void getClientAddrinfo(const char *host, const char *port);
};

#endif
