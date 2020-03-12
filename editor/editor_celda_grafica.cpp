#include "editor_celda_grafica.h"
#include "editor_defines.h"
#include <QtMath>


CeldaGrafica::CeldaGrafica() : ocupado(false), item(nullptr)
{

}

CeldaGrafica::~CeldaGrafica()
{
    if(this->ocupado) {
        delete this->item;
    }
}

bool CeldaGrafica::ocupada()
{
    return this->ocupado;
}

bool CeldaGrafica::libre()
{
    return !this->ocupado;
}

bool CeldaGrafica::abandonado()
{
    return (this->ocupada() && (this->getPosicionRelativaEscenario() != this->item->scenePos()));
}

void CeldaGrafica::guardar(YAML::Node &nodo)
{
    if(this->ocupado) {
        this->item->guardar(nodo);
    }
}

void CeldaGrafica::abrir(YAML::Node &nodo) {
    this->item->abrir(nodo);
}

void CeldaGrafica::recapturar()
{
    QPointF posicion = this->getPosicionRelativaEscenario();
    this->item->setPos(posicion);
}

void CeldaGrafica::ocupar(ItemGrafico *item)
{
    this->item = item;
    this->ocupado = true;
}

ItemGrafico *CeldaGrafica::liberar()
{
    this->ocupado = false;
    return this->item;
}

void CeldaGrafica::setPosicion(int posicion)
{
    this->posicion = posicion;
}

QPointF CeldaGrafica::getPosicionRelativaGrilla()
{
    QPointF posicion;
    int cantColumnas = qFloor(WINDOWS_SIZE_W/CELL_SIZE_W);
    posicion.setX(this->posicion % cantColumnas);
    posicion.setY(qFloor(this->posicion / cantColumnas));
    return posicion;
}

QPointF CeldaGrafica::getPosicionRelativaEscenario()
{
    QPointF posicion = this->getPosicionRelativaGrilla();
    posicion.setX(posicion.x() * CELL_SIZE_W);
    posicion.setY(posicion.y() * CELL_SIZE_H);
    return posicion;
}


