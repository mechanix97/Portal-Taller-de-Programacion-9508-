#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <iostream>
#include <cstring>

#include "../include/socket.h"
#include "../include/exceptions.h"

Socket::Socket() {
	this->fileDescriptor = -1;
	this->connected = false;
	this->ptr = nullptr;
}

Socket::Socket(int fd) {
	this->fileDescriptor = fd;
	this->connected = true;
	this->ptr = nullptr;
}

Socket::~Socket() {
	if(this->fileDescriptor != -1) {
		this->shutdown('f');
		::close(this->fileDescriptor);
		this->fileDescriptor = -1;
	}
	if (this->ptr != nullptr) {
		freeaddrinfo(this->ptr);
	}
}


int Socket::get() const{
	return this->fileDescriptor;
}

void Socket::close(){
	if(this->fileDescriptor != -1) {
		this->shutdown('f');
		::close(this->fileDescriptor);
		this->fileDescriptor = -1;
	}
}

//De uso para el cliente, conecta el socket a un determinado puerto.
void Socket::connect(const std::string& host, const std::string& port){
	try {
		int s;
		this->getClientAddrinfo(host.c_str(), port.c_str());
		struct addrinfo *_ptr;
		for (_ptr = this->ptr; (_ptr != NULL) && (!this->connected);
			_ptr = _ptr->ai_next) {
			this->setSocket(ptr);
			s = ::connect(this->fileDescriptor, _ptr->ai_addr, 
				_ptr->ai_addrlen);
			if (s == ERROR) {
				throw ConnectionErrorException("Error en connect: %s\n",
					strerror(errno));
			}
			this->connected = true;
		}
		if (!this->connected) {
			throw ConnectionErrorException(
				"Error en Socket::connect de common_sockets.cpp: "
				"no hubo conexion con ninguno de los addrinfo disponibles");
		}
	} catch (const std::exception &e) {
		std::cout << e.what();
		throw ConnectionErrorException("Error en Socket::connect, "
			"no se pudo conectar\n");
	}
}

void Socket::bindSocket(struct addrinfo *p) {
	int s = ::bind(this->fileDescriptor, p->ai_addr,p->ai_addrlen);
	if (s == ERROR) {
		::close(this->fileDescriptor);
		perror("ERROR");
		throw ConnectionErrorException("Error in socet::bind: %s\n",
		gai_strerror(s));
	}
}

//Enlaza el socket a una interfaz particular y queda en escucha
//hasta que entra una conexión. El socket ha de estar previamente creado.
void Socket::bindAndListen(const std::string& port) {
	int s;
	this->getServerAddrinfo(port.c_str());
	this->setSocket(this->ptr);
	this->bindSocket(this->ptr);
	s = listen(this->fileDescriptor, MAX_CONNECTIONS);
	if (s == ERROR) {
		throw ConnectionErrorException("Error: %s\n", strerror(errno));
	}
}

//accept_socket: devuelve un filedescriptor con el que se mantiene establecida
//la conexion con el client
Socket Socket::accept() {
	int s = ::accept(this->fileDescriptor, NULL, NULL);
	if (s == ERROR) {
		throw ConnectionErrorException("Error en socket::accept : %s\n",
		strerror(errno));
	}
	Socket socket(s);
	return std::move(socket);
}

//shutdown
//Desconecta el socket totalmente
void Socket::shutdown(char mode){
	if(this->fileDescriptor == -1) {
		return;
	}
	int s;
	switch( mode ){
		case 'f':
			s = ::shutdown(this->fileDescriptor, SHUT_RDWR);
			break;
		case 'r':
			s = ::shutdown(this->fileDescriptor, SHUT_RD);
			break;
		case 's':
			s = ::shutdown(this->fileDescriptor, SHUT_WR);
			break;
		default:
			s = ::shutdown(this->fileDescriptor, SHUT_RDWR);
			break;
	}
	if (s == ERROR) {
		throw ConnectionErrorException("Error en socket::shutdown: %s\n",
			strerror(errno));
	}
}

void Socket::setServerHints(struct addrinfo *hints) {
	memset(hints, 0, sizeof(struct addrinfo));
	hints->ai_family = SERVER_FAMILY;
	hints->ai_socktype = SERVER_SOCKTYPE;
	hints->ai_flags = SERVER_FLAGS;
}

void Socket::setClientHints(struct addrinfo *hints) {
	memset(hints, 0, sizeof(struct addrinfo));
	hints->ai_family = CLIENT_FAMILY;
	hints->ai_socktype = CLIENT_SOCKTYPE;
	hints->ai_flags = CLIENT_FLAGS;
}

void Socket::setSocket(struct addrinfo *p) {
	int s;
	int option = 1;
	s = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
	if (s == ERROR) {
		throw ConnectionErrorException(
			"Error: %s en setSocket de common_sockets.h\n", strerror(s));
	}
	this->fileDescriptor = s;
	setsockopt(this->fileDescriptor, SOL_SOCKET, SO_REUSEADDR, &option, 
		sizeof(option));
}

void Socket::getClientAddrinfo(const char *host, const char *port){
	int s;
	struct addrinfo hints;
	setClientHints(&hints);
	s = getaddrinfo(host, port, &hints, &this->ptr);
	if (s != 0) {
		throw ConnectionErrorException(
			"Error in getaddrinfo: %s\n", gai_strerror(s));
	}
}

void Socket::getServerAddrinfo(const char *port){
	int s;
	struct addrinfo hints;
	setServerHints(&hints);
	s = getaddrinfo(SERVER_NAME, port, &hints, &this->ptr);
	if (s != 0) {
		throw ConnectionErrorException("Error En getaddrinfo: %s\n",
			gai_strerror(s));
	}
}

int Socket::receive(void * ptr, size_t len) const{
	return ::recv(this->fileDescriptor,ptr,len,0);
}

int Socket::send(const void * ptr, size_t len) const{
	return ::send(this->fileDescriptor,ptr,len,MSG_NOSIGNAL);
}

Socket::Socket(Socket &&other) {
	this->fileDescriptor = other.fileDescriptor;
	this->connected = other.connected;
	this->ptr = other.ptr;

	other.ptr = nullptr;
	other.fileDescriptor = -1;
	other.connected = false;
}

Socket &Socket::operator=(Socket && other) {
	this->fileDescriptor = other.fileDescriptor;
	this->connected = other.connected;
	this->ptr = other.ptr;

	other.ptr = nullptr;
	other.fileDescriptor = -1;
	other.connected = false;

	return *this;
}
