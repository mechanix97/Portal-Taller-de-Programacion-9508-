#include "editor_item_grafico.h"
#include "editor_defines.h"

#include <QPointF>
#include <QtMath>

ItemGrafico::ItemGrafico(unsigned idClass) : idClass(idClass)
{
}

ItemGrafico::ItemGrafico(QString direccionSprite,
                         unsigned idClass) : sprite(direccionSprite),
                                             idClass(idClass)
{
}

ItemGrafico::~ItemGrafico()
{
}

int ItemGrafico::getIdCelda()
{
    QPointF posicion = this->scenePos();

    int i = qFloor(posicion.x() / CELL_SIZE_W);
    int j = qFloor(posicion.y() / CELL_SIZE_H);
    int columnas = qFloor(WINDOWS_SIZE_W / CELL_SIZE_W);
    int k = columnas * j + i;
    return k;
}

unsigned ItemGrafico::getIdClass()
{
    return this->idClass;
}

void ItemGrafico::guardar(YAML::Node &nodo)
{
    int idCelda = this->getIdCelda();
    nodo["celdas"][idCelda]["idClass"] = this->idClass;
    nodo["celdas"][idCelda]["idObject"] = idCelda;
    nodo["celdas"][idCelda]["x"] = this->scenePos().x();
    nodo["celdas"][idCelda]["y"] = this->scenePos().y();
}

void ItemGrafico::abrir(YAML::Node &nodo)
{
}