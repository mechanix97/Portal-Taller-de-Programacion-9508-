#include "editor_compuerta_and.h"
#include "editor_defines.h"

CompuertaAND::CompuertaAND() : Compuerta(DIR_IMAGEN_COMPUERTA_AND,
                                         IDCLASS_COMPUERTA_AND)
{
}

CompuertaAND::~CompuertaAND()
{
}

bool CompuertaAND::tieneReglasBienDefinidas()
{
    unsigned contador = 0;
    QList<item_logica_t> items = this->logica.values();
    for (int i = 0; i < items.size(); i++)
    {
        contador += (items[i].es_parte ? 1 : 0);
    }
    return (contador > 0);
}