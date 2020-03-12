#include "editor_roca.h"
#include "editor_defines.h"

Roca::Roca() : ItemGrafico(DIR_IMAGEN_ROCA, IDCLASS_ROCA)
{
    this->sprite = this->sprite.scaled(CELL_SIZE_W, CELL_SIZE_H);
    this->setPixmap(this->sprite);
}

Roca::~Roca()
{
}