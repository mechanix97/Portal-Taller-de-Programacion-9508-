#include "editor_acido.h"
#include "editor_defines.h"

Acido::Acido() : ItemGrafico(DIR_IMAGEN_ACIDO, IDCLASS_ACIDO)
{
    this->sprite = this->sprite.scaled(CELL_SIZE_W*2, CELL_SIZE_H);
    this->setPixmap(this->sprite);
}

Acido::~Acido()
{
}