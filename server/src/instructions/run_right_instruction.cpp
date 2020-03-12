#include "../../include/instructions/run_right_instruction.h"

#include "../../include/instructions/instruction.h"
#include "../../include/bodies/chell/chell.h"


RunRightInstruction::RunRightInstruction(Chell *chell):
    chell(chell) {
}

void RunRightInstruction::execute() {
    this->chell->pressRight();
}
