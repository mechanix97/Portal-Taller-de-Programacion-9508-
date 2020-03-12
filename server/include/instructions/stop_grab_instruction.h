#ifndef __STOP_GRAB_INSTRUCTION_H__
#define __STOP_GRAB_INSTRUCTION_H__

#include "instruction.h"

class Chell;

class StopGrabInstruction: public Instruction {
private:
    Chell *chell;

public:
    /* Instancia una instruccion para liberar el boton grab de chell */
    StopGrabInstruction(Chell *chell);

    /* Ejecuta la instruccion */
    virtual void execute();
};

#endif
