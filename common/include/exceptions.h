#ifndef _COMMON_EXCEPTIONS_H_
#define _COMMON_EXCEPTIONS_H_

#include <exception>
#include <string>
#include <cstring>
#include <errno.h>
#include <cstdarg>
#include <cstdio>

#define BUF_LEN 512

class genericError : public std::exception {
protected:
  	int _errno;
  	char msg_error[BUF_LEN];
public:
  	explicit genericError(const char *msg, ...) noexcept;
  	virtual ~genericError() noexcept {};
  	const char *what() const noexcept;
};

class ConnectionErrorException: public std::exception {
  	int _errno;
  	char msg_error[BUF_LEN];
public:
	explicit ConnectionErrorException(const char *msg, ...) noexcept;
  	virtual ~ConnectionErrorException() noexcept {};
    const char *what() const noexcept;
};

#endif
