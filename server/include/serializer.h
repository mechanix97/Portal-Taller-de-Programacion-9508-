#ifndef __SERIALIZER_H__
#define __SERIALIZER_H__

#include <string>
#include "yaml-cpp/yaml.h"
#include "../../common/include/types.h"
#include "../../server/include/boolean_suppliers/boolean_supplier.h"
#include <cstdint>

class World;
class Gate;
class Receiver;
class Button;

struct GateLogic {
    std::map<int, Gate *> gates;
    std::map<int, BooleanSupplier *> booleansups;
};

class Serializer {
public:
    /* Carga el contenido de un mapa en world desde filepath y la
    * configuracion desde configpath.*/
    void deserialize(
        World *world,
        std::string filepath,
        std::string configpath) const;

private:
    /* Deserializa un mapa y lo carga en world*/
    void deserializeMap(World *world, std::string filepath) const;

    /* Deserializa una configuracion y la carga en world*/
    void deserializeConfig(World *world, std::string configpath) const;

    /* Deserializa un body en world*/
    void deserializeBody(
        World *world, const YAML::Node &celda,
        GateLogic &gate_logic) const;

    /* Contecta compuertas, botones y receptores*/
    void connect(
        const YAML::Node &config,
        GateLogic &gate_logic) const;

    /* Agrega a una compuerta boolean suppliers.
     * El item puede estar negado */
    void add(Gate *gate, BooleanSupplier *booleansup, bool negate) const;

    /* Obtiene el nombre de un archivo desde una direccion absoluta */
    std::string getBackgroundFile(std::string absolute_path) const;
};

#endif
