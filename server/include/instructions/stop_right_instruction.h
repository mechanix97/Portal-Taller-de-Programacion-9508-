#ifndef __STOP_RIGHT_INSTRUCTION_H__
#define __STOP_RIGHT_INSTRUCTION_H__

#include "instruction.h"

class Chell;

class StopRightInstruction: public Instruction {
private:
    Chell *chell;

public:
    StopRightInstruction(Chell *chell);
    virtual void execute() override;
};

#endif
