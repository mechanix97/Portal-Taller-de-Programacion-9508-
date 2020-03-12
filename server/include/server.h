#ifndef __SERVER_H__
#define __SERVER_H__

#include "accepter.h"
#include <iostream>

class Server {
private:
    const char *port;
    
public:
    Server(const char *port);
    int main();
};

#endif
