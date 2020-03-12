#ifndef __PRESS_GRAB_INSTRUCTION_H__
#define __PRESS_GRAB_INSTRUCTION_H__

#include "instruction.h"

class Chell;

class PressGrabInstruction: public Instruction {
private:
    Chell *chell;
    
public:
    /* Instancia una instruccion para ejecutar pressGrab sobre chell */
    PressGrabInstruction(Chell *chell);

    /* Ejecuta la instruccion */
    virtual void execute();
};

#endif
