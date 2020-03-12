#include "editor_compuerta_regular.h"
#include "editor_defines.h"
CompuertaRegular::CompuertaRegular() : Compuerta(DIR_IMAGEN_COMPUERTA_REG,
                                                 IDCLASS_COMPUERTA_REG)
{
}

CompuertaRegular::~CompuertaRegular()
{
}

bool CompuertaRegular::tieneReglasBienDefinidas()
{
    unsigned contador = 0;
    QList<item_logica_t> items = this->logica.values();
    for (int i = 0; i < items.size(); i++)
    {
        contador += (items[i].es_parte ? 1 : 0);
    }
    return (contador == 1);
}
