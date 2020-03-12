#ifndef __DESTROY_BODY_INSTRUCTION_H__
#define __DESTROY_BODY_INSTRUCTION_H__

#include "instruction.h"

class Body;

class DestroyBodyInstruction: public Instruction {
private:
    Body *body;

public:
    DestroyBodyInstruction(Body *body);
    virtual void execute() override;
};

#endif
