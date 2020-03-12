#if !defined(EDITOR_COMPUERTA_OR_H)
#define EDITOR_COMPUERTA_OR_H

#include "editor_compuerta.h"

class CompuertaOR : public Compuerta
{
private:
public:
    CompuertaOR();
    ~CompuertaOR();

    virtual bool tieneReglasBienDefinidas();
};

#endif // EDITOR_COMPUERTA_OR_H
