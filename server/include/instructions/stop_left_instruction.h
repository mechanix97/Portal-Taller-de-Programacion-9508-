#ifndef __STOP_LEFT_INSTRUCTION_H__
#define __STOP_LEFT_INSTRUCTION_H__

#include "instruction.h"

class Chell;

class StopLeftInstruction: public Instruction {
private:
    Chell *chell;

public:
    StopLeftInstruction(Chell *chell);
    virtual void execute() override;
};

#endif
