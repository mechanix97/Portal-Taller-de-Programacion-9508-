#include "editor_bloque_de_roca.h"
#include "editor_defines.h"

BloqueDeRoca::BloqueDeRoca() : ItemGrafico(DIR_IMAGEN_BLOQUE_ROCA, IDCLASS_BLOQUE_ROCA)
{
    this->sprite = this->sprite.scaled(CELL_SIZE_W, CELL_SIZE_H);
    this->setPixmap(this->sprite);
}

BloqueDeRoca::~BloqueDeRoca()
{
}