# Makefile solo para evitar tener que escribir ciertos commands que no se
# se puedan agregar a CMake

all:
	cd ./build && cmake .. && make
	cd ./editor/build && cmake .. && make
	
install:
	cd ./build && cmake -DCMAKE_INSTALL_PREFIX=${IPATH} .. && make install
	cd ./editor/build && cmake -DCMAKE_INSTALL_PREFIX=${IPATH} .. && make install

# Corre el entorno de pruebas de Box2D
testbed:
	cd libs/Box2D-master/ && ../premake5 gmake && make -C Build/ && cd Testbed && ../Build/bin/x86_64/Debug/Testbed

valgrind-client:
	cd build && valgrind --leak-check=full --show-leak-kinds=all --suppressions=../libs/valgrind-supp/minimal.supp ./client

valgrind-server:
	cd build && valgrind --leak-check=full --show-leak-kinds=all --suppressions=../libs/valgrind-supp/minimal.supp ./server
	
# Copia SOLO los archivos del directorio SRCD a DESTD, sin copiar la 
# estructura de directorios.
# Uso: make copy-rec SRCD=dir0 DEST=dir1
copy-rec:
	find ${SRCD} -type f -exec cp -t ${DESTD} {} +

.PHONY: testbed install uninstall all valgrind-client valgrind-server copy-rec
