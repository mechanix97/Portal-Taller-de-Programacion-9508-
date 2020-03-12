#ifndef __FIRE_PORTAL_INSTRUCTION_H__
#define __FIRE_PORTAL_INSTRUCTION_H__

#include "instruction.h"
#include <cstdint>

class Chell;

class FirePortalInstruction: public Instruction {
private:
    Chell *chell;
    uint8_t number;
    float x;
    float y;

public:
    FirePortalInstruction(Chell *chell, uint8_t number, float x, float y);
    virtual void execute();
};

#endif
