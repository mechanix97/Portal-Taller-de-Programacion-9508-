#if !defined(EDITOR_COMPUERTA_REGULAR_H)
#define EDITOR_COMPUERTA_REGULAR_H

#include "editor_compuerta.h"

class CompuertaRegular : public Compuerta
{
private:
public:
    CompuertaRegular();
    ~CompuertaRegular();

    virtual bool tieneReglasBienDefinidas();
};

#endif // EDITOR_COMPUERTA_REGULAR_H
