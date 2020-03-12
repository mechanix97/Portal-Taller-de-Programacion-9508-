#if !defined(EDITOR_COMPUERTA_H)
#define EDITOR_COMPUERTA_H

#include "editor_item_grafico.h"
#include "editor_componente_compuerta.h"
#include "editor_item_logica.h"
#include <yaml-cpp/yaml.h>

class Compuerta : public ItemGrafico
{
private:
protected:
    QMap<ComponenteCompuerta *, item_logica_t> logica;

public:
    Compuerta(QString direccionSprite, unsigned idClass);
    ~Compuerta();

    virtual void eliminar(ComponenteCompuerta *componente);
    virtual void agregar(ComponenteCompuerta *componente);
    virtual void agregar(QList<ComponenteCompuerta *> componentes);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;

    virtual void guardar(YAML::Node &nodo);
    virtual void abrirComponentes(YAML::Node &nodo);

    virtual bool tieneReglasBienDefinidas() = 0;
};

#endif // EDITOR_COMPUERTA_H
