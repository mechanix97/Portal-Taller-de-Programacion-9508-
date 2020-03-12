#include "editor_barrera_de_energia.h"
#include "editor_defines.h"

BarreraDeEnergia::BarreraDeEnergia(unsigned idClass) : ItemGrafico(idClass)
{
    if (this->idClass == IDCLASS_BARRERA_VERTICAL)
    {
        QPixmap spriteBarrera(DIR_IMAGEN_BARRERA_V);
        this->sprite = spriteBarrera.scaled(CELL_SIZE_W, CELL_SIZE_H * 2);
        this->setPixmap(this->sprite);
    }
    else if (this->idClass == IDCLASS_BARRERA_HORIZONTAL)
    {
        QPixmap spriteBarrera(DIR_IMAGEN_BARRERA_H);
        this->sprite = spriteBarrera.scaled(CELL_SIZE_W*2, CELL_SIZE_H);
        this->setPixmap(this->sprite);
    }
}

BarreraDeEnergia::~BarreraDeEnergia()
{
}