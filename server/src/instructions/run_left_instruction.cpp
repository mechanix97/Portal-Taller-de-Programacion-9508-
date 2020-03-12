#include "../../include/instructions/run_left_instruction.h"

#include "../../include/instructions/instruction.h"
#include "../../include/bodies/chell/chell.h"


RunLeftInstruction::RunLeftInstruction(Chell *chell):
    chell(chell) {
}

void RunLeftInstruction::execute() {
    this->chell->pressLeft();
}
