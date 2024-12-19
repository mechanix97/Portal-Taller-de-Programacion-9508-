# TP Final Taller de Programacion 1

[![YouTube](http://i.ytimg.com/vi/zYuNiUTCyk0/hqdefault.jpg)](https://www.youtube.com/watch?v=zYuNiUTCyk0)

## Informes
[Manual de Usuario](https://www.overleaf.com/8662443479fxhrvfhpcpjb)    
[Documentacion Tecnica](https://www.overleaf.com/5422846237hqmsxttbympm)    
[Manual de Proyecto](https://www.overleaf.com/8295884323xsbzrjvqpbzw)   

## Instalacion de ffmpeg y bibliotecas adicionales en ubuntu
```
sudo apt install ffmpeg
sudo apt install libavformat-dev
```

## Instalacion de SDL2
```
sudo apt install libsdl2-mixer-2.0-0
sudo apt install libsdl2-mixer-dev
sudo apt-get install libsdl2-ttf-dev
```
Ademas necesita a Tiff (por alguna razon).
```
sudo apt install libtiff5
sudo apt install libtiff-opengl libtiffxx
sudo apt install libtiff5-dev
sudo apt install libtiff-tools
sudo apt install libtiff-dev
```


## Instalacion de CMAKE

```
sudo apt-get -y install cmake
```

## Instalacion de YAML

- Clonar el siguiente repositorio: <https://github.com/jbeder/yaml-cpp/>
- Descomprimir el .zip en $HOME o algun lugar destinado a aplicaciones.
- Abrir terminal en la carpeta descomprimida y ejecutar los siguientes comando

```
mkdir build
cd build/
cmake ..
make
sudo make install
```

**Opcional:** para agregar a cmake incluir las siguientes lineas en las en el archivo CMakeLists.txt

```
find_package(yaml-cpp REQUIRED)
#add_executable(main main.cpp)
target_link_libraries(main yaml-cpp)
```

## Instalacion de QT

```
sudo apt-get install build-essential
sudo apt-get install qtcreator
sudo apt-get install qt5-default
```

## Instalacion de CxxTest

Para poder correr los tests lo mas facil es instalar CxxTest en ubuntu mediante
~~~
sudo apt update
sudo apt install cxxtest
~~~

## Agregar tests
Los test deben ser agregados en el directorio test y deben seguir la siguiente
estructura.

~~~
# Suponer que esta en ./test/my_test.h
#include <cxxtest/TestSuite.h>

class MyTestSuite : public CxxTest::TestSuite {
public:
   void testAddition() {
       int a = 3;
       int b = 2;  
       TS_ASSERT_EQUALS(5, a + b);
   }
};
~~~

- Deben ser headers (.h)
- Deben incluir la biblioteca `#include <cxxtest/TestSuite.h>`.
- Son clases que heredan de `CxxTest::TestSuite`
- Los test son metodos y siguen el estilo
  `void testXXXXX(void) { <codigo> }`
- Para checkear condiciones se suele utilizar `TEST_ASSERT(expr)`,
 `TEST_ASSERT_EQUALS(x, y)`, `TS_ASSERT_THROWS(expr,type)`. Hay mas en
  http://cxxtest.com/guide.html#testAssertions.

## Ejecucion
Solo basta con ejecutar en build
~~~
cmake ..
make
./unittest
~~~

Una correcta ejecucion deberia verse como
~~~
Running cxxtest tests (1 test).OK!
~~~

Y una con problemas
~~~
Running cxxtest tests (1 test)
In MyTestSuite::testAddition:
../test/foo_test.h:10: Error: Expected (99 == a + b), found (99 != 5)
Failed 1 and Skipped 0 of 1 test
Success rate: 0%
~~~
