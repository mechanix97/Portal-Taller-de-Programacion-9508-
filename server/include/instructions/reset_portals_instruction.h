#ifndef __RESET_PORTALS_INSTRUCTION_H__
#define __RESET_PORTALS_INSTRUCTION_H__

#include "instruction.h"

class Chell;

class ResetPortalsInstruction: public Instruction {
private:
    Chell *chell;

public:
    ResetPortalsInstruction(Chell *chell);
    virtual void execute() override;
};

#endif
