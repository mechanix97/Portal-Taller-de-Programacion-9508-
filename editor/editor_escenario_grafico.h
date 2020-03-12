#ifndef EDITOR_ESCENARIO_GRAFICO_H
#define EDITOR_ESCENARIO_GRAFICO_H

#include <QGraphicsScene>
#include <QSpinBox>
#include <string>
#include <QSize>
#include <QList>
#include "yaml-cpp/yaml.h"
#include "editor_item_grafico.h"
#include "editor_celda_grafica.h"
#include "editor_compuerta.h"
#include "editor_componente_compuerta.h"

class EscenarioGrafico : public QGraphicsScene
{
private:
    QSpinBox *spinBoxX;
    QSpinBox *spinBoxY;
    QSize tamanio;
    QVector<CeldaGrafica> celdas;
    QList<Compuerta *> compuertas;
    QList<ComponenteCompuerta *> componentesCompuerta;

    std::string fondoEscenario;
    unsigned idClassACrear;

    unsigned cantidadChells;
    unsigned cantidadPasteles;

public:
    EscenarioGrafico();
    virtual ~EscenarioGrafico();
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

    void setSpinBox(QSpinBox *spinBoxX_, QSpinBox *spinBoxY_);
    void setFondoEscenario(std::string direccion, QSize tamanio);
    void setIdClassACrear(unsigned idClass);

    void agregarACeldas(ItemGrafico *item, QPointF posicion);
    void crearItem(QPointF posicion);
    void moverItem(QPointF posicion);

    CeldaGrafica &getCelda(QPointF posicion);

    void guardar(YAML::Node &nodo);
    void abrir(YAML::Node &nodo);
};

#endif // EDITOR_ESCENARIO_GRAFICO_H
