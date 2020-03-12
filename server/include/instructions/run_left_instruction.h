#ifndef __RUN_LEFT_INSTRUCTION_H__
#define __RUN_LEFT_INSTRUCTION_H__

#include "instruction.h"

class Chell;

class RunLeftInstruction: public Instruction {
private:
    Chell *chell;

public:
    RunLeftInstruction(Chell *chell);
    virtual void execute() override;
};

#endif
