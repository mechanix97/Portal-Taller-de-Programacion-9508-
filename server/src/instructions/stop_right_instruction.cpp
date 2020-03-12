#include "../../include/instructions/stop_right_instruction.h"

#include "../../include/instructions/instruction.h"
#include "../../include/bodies/chell/chell.h"


StopRightInstruction::StopRightInstruction(Chell *chell):
    chell(chell) {
}

void StopRightInstruction::execute() {
    this->chell->releaseRight();
}
