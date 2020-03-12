#include "editor_boton.h"
#include "editor_defines.h"
#include <QInputDialog>

Boton::Boton() : ComponenteCompuerta(DIR_IMAGEN_BOTON, IDCLASS_BOTON)
{
    this->sprite = this->sprite.scaled(CELL_SIZE_W * 2, CELL_SIZE_H);
    this->setPixmap(this->sprite);
}

Boton::~Boton()
{
}

void Boton::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    this->nombre = QInputDialog::getText(nullptr,
                                         "Nombrando un Boton",
                                         "Ingrese un nombre para el boton: ");
}

QString Boton::getTipoStr()
{
    return "Boton";
}