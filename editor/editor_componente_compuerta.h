#if !defined(EDITOR_COMPONENTE_COMPUERTA_H)
#define EDITOR_COMPONENTE_COMPUERTA_H

#include <QString>
#include "editor_item_grafico.h"

class ComponenteCompuerta : public ItemGrafico
{
private:
protected:
    QString nombre;

public:
    ComponenteCompuerta(QString direccionSprite, unsigned idClass);
    virtual ~ComponenteCompuerta();
    virtual QString getNombre();
    virtual QString getTipoStr() = 0;
    virtual void guardar(YAML::Node &nodo);
    virtual void abrir(YAML::Node &nodo);
};

#endif // EDITOR_COMPONENTE_COMPUERTA_H
