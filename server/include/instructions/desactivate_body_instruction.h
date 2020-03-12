#ifndef __DESACTIVATE_BODY_INSTRUCTION_H__
#define __DESACTIVATE_BODY_INSTRUCTION_H__

#include "instruction.h"

class Body;

class DesactivateBodyInstruction: public Instruction {
private:
    Body *body;

public:
    /* Instancia una instruccion de desactivacion de un body */
    DesactivateBodyInstruction(Body *body);

    /* Ejecuta la instruccion */
    virtual void execute();
};

#endif
