#ifndef __JUMP_INSTRUCTION_H__
#define __JUMP_INSTRUCTION_H__

#include "instruction.h"

class Chell;

class JumpInstruction: public Instruction {
private:
    Chell *chell;

public:
    JumpInstruction(Chell *chell);
    virtual void execute() override;
};

#endif
