#include "editor_componente_compuerta.h"
#include <string>

ComponenteCompuerta::ComponenteCompuerta(
    QString direccionSprite, unsigned idClass)
    : ItemGrafico(direccionSprite, idClass)
{
}

ComponenteCompuerta::~ComponenteCompuerta()
{
}

QString ComponenteCompuerta::getNombre()
{
    return this->nombre;
}

void ComponenteCompuerta::guardar(YAML::Node &nodo)
{
    std::string nombreStdStr = this->nombre.toStdString();
    ItemGrafico::guardar(nodo);
    int idCelda = this->getIdCelda();
    nodo["celdas"][idCelda]["nombre"] = nombreStdStr;
}

void ComponenteCompuerta::abrir(YAML::Node &nodo)
{
    int idCelda = this->getIdCelda();
    std::string nombreStdStr =
        nodo["celdas"][idCelda]["nombre"].as<std::string>();
    this->nombre = QString::fromStdString(nombreStdStr);
}