#ifndef __GRAB_ROCK_INSTRUCTION_H__
#define __GRAB_ROCK_INSTRUCTION_H__

#include "instruction.h"

class Chell;
class Rock;

class GrabRockInstruction: public Instruction {
private:
    Chell *chell;
    Rock *rock;
    
public:
    /* Instancia una instruccion para que chell tome una roca */
    GrabRockInstruction(Chell *chell, Rock *rock);

    /* Ejecuta la instruccion */
    virtual void execute();
};

#endif
