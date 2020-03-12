#include "../../include/instructions/stop_left_instruction.h"

#include "../../include/instructions/instruction.h"
#include "../../include/bodies/chell/chell.h"


StopLeftInstruction::StopLeftInstruction(Chell *chell):
    chell(chell) {
}

void StopLeftInstruction::execute() {
    this->chell->releaseLeft();
}
