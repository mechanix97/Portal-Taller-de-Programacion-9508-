#include "editor_receptor.h"
#include "editor_defines.h"
#include <QInputDialog>

Receptor::Receptor() : ComponenteCompuerta(DIR_IMAGEN_RECEPTOR,
                                           IDCLASS_RECEPTOR)
{
    this->sprite = this->sprite.scaled(CELL_SIZE_W, CELL_SIZE_H);
    this->setPixmap(this->sprite);
}

Receptor::~Receptor()
{
}

void Receptor::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    this->nombre = QInputDialog::getText(nullptr,
                                         "Nombrando un receptor",
                                         "Ingrese un nombre para el boton: ");
}

QString Receptor::getTipoStr()
{
    return "Receptor";
}