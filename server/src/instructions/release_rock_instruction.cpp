#include "../../include/instructions/release_rock_instruction.h"
#include "../../include/bodies/chell/chell.h"

ReleaseRockInstruction::ReleaseRockInstruction(Chell *chell):
    chell(chell) {
}

void ReleaseRockInstruction::execute() {
    chell->releaseRock();
}
