#include "editor_compuerta_or.h"
#include "editor_defines.h"

CompuertaOR::CompuertaOR() : Compuerta(DIR_IMAGEN_COMPUERTA_OR,
                                       IDCLASS_COMPUERTA_OR)
{
}

CompuertaOR::~CompuertaOR()
{
}

bool CompuertaOR::tieneReglasBienDefinidas()
{
    unsigned contador = 0;
    QList<item_logica_t> items = this->logica.values();
    for (int i = 0; i < items.size(); i++)
    {
        contador += (items[i].es_parte ? 1 : 0);
    }
    return (contador > 0);
}
