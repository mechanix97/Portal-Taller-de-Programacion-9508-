#if !defined(EDITOR_BOTON_H)
#define EDITOR_BOTON_H

#include "editor_componente_compuerta.h"
#include <QString>

class Boton : public ComponenteCompuerta
{
private:
public:
    Boton();
    virtual ~Boton();
    virtual QString getTipoStr();
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // EDITOR_BOTON_H
