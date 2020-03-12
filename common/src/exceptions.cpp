#include <exception>
#include <string>
#include <cstring>
#include <errno.h>
#include <cstdarg>
#include <cstdio>

#include "../include/exceptions.h"

genericError::genericError(const char *msg, ...) noexcept {
  	va_list args;
  	va_start(args, msg);
  	vsnprintf(&this->msg_error[0], BUF_LEN, msg, args);
  	va_end(args);
  	msg_error[BUF_LEN - 1] = '\0';
}

const char *genericError::what() const noexcept {
  	return &this->msg_error[0];
}

ConnectionErrorException::
ConnectionErrorException(const char *msg, ...) noexcept {
  	va_list args;
  	va_start(args, msg);
  	vsnprintf(&this->msg_error[0], BUF_LEN, msg, args);
  	va_end(args);
  	msg_error[BUF_LEN - 1] = '\0';
}

const char *ConnectionErrorException::what() const noexcept {
  	return &this->msg_error[0];
}
