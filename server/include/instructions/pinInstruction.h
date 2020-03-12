#ifndef _PIN_INSTRUCTION_H_
#define _PIN_INSTRUCTION_H_

#include <cstdint>

#include "instruction.h"
#include "../../include/world.h"
#include "../../include/pin.h"

class Chell;

class PinInstruction : public Instruction {
private:
	World* world;
	uint32_t id;
	int32_t param1;
    int32_t param2;
public:
	explicit PinInstruction(World* world,uint32_t id,int32_t param1,int32_t param2);
    ~PinInstruction();
    virtual void execute() override;	
};

#endif
