#if !defined(EDITOR_COMPUERTA_AND_H)
#define EDITOR_COMPUERTA_AND_H

#include "editor_compuerta.h"

class CompuertaAND : public Compuerta
{
private:
public:
    CompuertaAND();
    ~CompuertaAND();

    virtual bool tieneReglasBienDefinidas();
};

#endif // EDITOR_COMPUERTA_AND_H
