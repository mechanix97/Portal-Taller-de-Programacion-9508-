#ifndef __RELEASE_ROCK_INSTRUCTION_H__
#define __RELEASE_ROCK_INSTRUCTION_H__

#include "instruction.h"

class Chell;

class ReleaseRockInstruction: public Instruction {
private:
    Chell *chell;

public:
    /* Instancia una instruccion para que chell suelte una roca */
    ReleaseRockInstruction(Chell *chell);

    /* Ejecuta la instruccion */
    virtual void execute();
};

#endif
