#ifndef __DEFAULT_INSTRUCTION_H__
#define __DEFAULT_INSTRUCTION_H__

#include "instruction.h"

class DefaultInstruction: public Instruction {
public:
    virtual void execute() override;
};

#endif
