#ifndef EDITOR_ITEM_GRAFICO_H
#define EDITOR_ITEM_GRAFICO_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QString>
#include <string>
#include <QPointF>
#include <yaml-cpp/yaml.h>

class ItemGrafico : public QGraphicsPixmapItem
{
protected:
    QPixmap sprite;
    unsigned idClass;

public:
    ItemGrafico(unsigned idClass);
    ItemGrafico(QString direccionSprite, unsigned idClass);
    virtual ~ItemGrafico();

    int getIdCelda();
    unsigned getIdClass();
    virtual void guardar(YAML::Node &nodo);
    virtual void abrir(YAML::Node &nodo);
};

#endif // EDITOR_ITEM_GRAFICO_H
