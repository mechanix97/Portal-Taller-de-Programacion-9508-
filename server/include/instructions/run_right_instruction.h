#ifndef __RUN_RIGHT_INSTRUCTION_H__
#define __RUN_RIGHT_INSTRUCTION_H__

#include "instruction.h"

class Chell;

class RunRightInstruction: public Instruction {
private:
    Chell *chell;

public:
    RunRightInstruction(Chell *chell);
    virtual void execute() override;
};

#endif
