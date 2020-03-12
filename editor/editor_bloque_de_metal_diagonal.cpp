#include "editor_bloque_de_metal_diagonal.h"
#include "editor_defines.h"

BloqueDeMetalDiagonal::BloqueDeMetalDiagonal(unsigned idClass)
    : ItemGrafico(idClass)
{
    if (this->idClass == IDCLASS_DIAGONAL_0)
    {
        QPixmap spriteBloque(DIR_IMAGEN_DIAGONAL_0);
        this->sprite = spriteBloque.scaled(CELL_SIZE_W, CELL_SIZE_H);
        this->setPixmap(this->sprite);
    }
    else if (this->idClass == IDCLASS_DIAGONAL_90)
    {
        QPixmap spriteBloque(DIR_IMAGEN_DIAGONAL_90);
        this->sprite = spriteBloque.scaled(CELL_SIZE_W, CELL_SIZE_H);
        this->setPixmap(this->sprite);
    }
    else if (this->idClass == IDCLASS_DIAGONAL_180)
    {
        QPixmap spriteBloque(DIR_IMAGEN_DIAGONAL_180);
        this->sprite = spriteBloque.scaled(CELL_SIZE_W, CELL_SIZE_H);
        this->setPixmap(this->sprite);
    }
    else if (this->idClass == IDCLASS_DIAGONAL_270)
    {
        QPixmap spriteBloque(DIR_IMAGEN_DIAGONAL_270);
        this->sprite = spriteBloque.scaled(CELL_SIZE_W, CELL_SIZE_H);
        this->setPixmap(this->sprite);
    }
}

BloqueDeMetalDiagonal::~BloqueDeMetalDiagonal()
{
}
