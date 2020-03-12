#include "../include/server.h"

Server::Server(const char *port):
    port(port) {
}

int Server::main() {

    Accepter accepter(this->port);
    accepter.start();

    const char QUIT = 'q';
    while (std::cin.get() != QUIT) {
    }

    accepter.stop();
    accepter.join();

    return 0;
}
