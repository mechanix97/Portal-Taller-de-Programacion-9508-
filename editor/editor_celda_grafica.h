#ifndef EDITOR_CELDA_GRAFICA_H
#define EDITOR_CELDA_GRAFICA_H

#include "editor_item_grafico.h"
#include <yaml-cpp/yaml.h>

class CeldaGrafica
{
private:
    bool ocupado;
    ItemGrafico *item;
    int posicion;
public:
    CeldaGrafica();
    virtual ~CeldaGrafica();

    bool ocupada();
    bool libre();
    bool abandonado();
    void guardar(YAML::Node &nodo);
    void abrir(YAML::Node &nodo);

    void recapturar();
    void ocupar(ItemGrafico *item);
    ItemGrafico *liberar();
    void setPosicion(int posicion);
    QPointF getPosicionRelativaGrilla();
    QPointF getPosicionRelativaEscenario();
};

#endif // EDITOR_CELDA_GRAFICA_H
