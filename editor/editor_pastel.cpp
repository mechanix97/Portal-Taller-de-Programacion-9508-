#include "editor_pastel.h"
#include "editor_defines.h"

Pastel::Pastel(unsigned &contador)
    : ItemGrafico(DIR_IMAGEN_PASTEL, IDCLASS_PASTEL),
      contador(contador)
{
    this->sprite = this->sprite.scaled(CELL_SIZE_W, CELL_SIZE_H);
    this->setPixmap(this->sprite);
    this->contador += 1;
}

Pastel::~Pastel()
{
    this->contador -= 1;
}