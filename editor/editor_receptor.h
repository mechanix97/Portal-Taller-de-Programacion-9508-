#if !defined(EDITOR_RECEPTOR_H)
#define EDITOR_RECEPTOR_H

#include "editor_componente_compuerta.h"
#include <QString>

class Receptor : public ComponenteCompuerta
{
private:
public:
    Receptor();
    ~Receptor();

    virtual QString getTipoStr();
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // EDITOR_RECEPTOR_H
