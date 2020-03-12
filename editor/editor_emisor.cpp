#include "editor_emisor.h"
#include "editor_defines.h"

Emisor::Emisor(unsigned idClass) : ItemGrafico(idClass)
{
    if (this->idClass == IDCLASS_EMISOR_0)
    {
        QPixmap spriteBarrera(DIR_IMAGEN_EMISOR_0);
        this->sprite = spriteBarrera.scaled(CELL_SIZE_W, CELL_SIZE_H);
        this->setPixmap(this->sprite);
    }
    else if (this->idClass == IDCLASS_EMISOR_90)
    {
        QPixmap spriteBarrera(DIR_IMAGEN_EMISOR_90);
        this->sprite = spriteBarrera.scaled(CELL_SIZE_W, CELL_SIZE_H);
        this->setPixmap(this->sprite);
    }
    else if (this->idClass == IDCLASS_EMISOR_180)
    {
        QPixmap spriteBarrera(DIR_IMAGEN_EMISOR_180);
        this->sprite = spriteBarrera.scaled(CELL_SIZE_W, CELL_SIZE_H);
        this->setPixmap(this->sprite);
    }
    else if (this->idClass == IDCLASS_EMISOR_270)
    {
        QPixmap spriteBarrera(DIR_IMAGEN_EMISOR_270);
        this->sprite = spriteBarrera.scaled(CELL_SIZE_W, CELL_SIZE_H);
        this->setPixmap(this->sprite);
    }
}

Emisor::~Emisor()
{
}
