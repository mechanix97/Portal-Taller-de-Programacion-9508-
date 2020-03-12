#ifndef __INSTRUCTION_FACTORY_H__
#define __INSTRUCTION_FACTORY_H__

#include "instruction.h"
#include "../.././common/include/action.h"
#include "../bodies/chell/chell.h"
#include <cstdint>
#include <map>

class World;

class InstructionFactory {
public:
    Instruction *createInstruction(
        const Action &action,
        std::map<uint32_t, Chell *> &chells,
        World* world) const;
};

#endif
