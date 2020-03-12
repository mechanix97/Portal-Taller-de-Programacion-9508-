#include "editor_personaje_chell.h"
#include "editor_defines.h"

PersonajeChell::PersonajeChell(unsigned &contador)
    : ItemGrafico(DIR_IMAGEN_CHELL_A, IDCLASS_CHELL),
      contador(contador)
{
    this->sprite = this->sprite.scaled(CELL_SIZE_W, CELL_SIZE_H * 2);
    this->setPixmap(this->sprite);
    this->contador += 1;
}

PersonajeChell::~PersonajeChell()
{
    this->contador -= 1;
}
