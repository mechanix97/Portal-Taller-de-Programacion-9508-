#if !defined(EDITOR_PASTEL_H)
#define EDITOR_PASTEL_H

#include "editor_item_grafico.h"

class Pastel : public ItemGrafico
{
private:
    unsigned &contador;

public:
    Pastel(unsigned &contador);
    ~Pastel();
};

#endif // EDITOR_PASTEL_H
