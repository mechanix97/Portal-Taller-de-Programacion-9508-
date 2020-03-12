#include "../../include/instructions/jump_instruction.h"

#include "../../include/instructions/instruction.h"
#include "../../include/bodies/chell/chell.h"

JumpInstruction::JumpInstruction(Chell *chell):
    chell(chell) {
}

void JumpInstruction::execute() {
    this->chell->pressUp();
}
