#ifndef __JIG_INSTRUCTION_H__
#define __JIG_INSTRUCTION_H__

#include "instruction.h"

class Chell;

class JigInstruction: public Instruction {
private:
    Chell *chell;

public:
    /* Instancia una instruccion de bailar */
    JigInstruction(Chell *chell);

    /* Ejecuta la instruccion */
    virtual void execute();
};

#endif
