#include "../include/client.h"
#include <string>
#include <iostream>

#define ARG_MAIN_CLIENT 2

int main(int argc, char *argv[]) {

	if (argc != ARG_MAIN_CLIENT) {
		std::cout << "Error: Cantidad de argumentos invalida."
				  << "\nModo de uso: ./portal-client <PORT>"
				  << std::endl;
		return 1;
	}

	try{
		Client client(argv[NPORT]);
	    client.main();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
	return 0;
}
