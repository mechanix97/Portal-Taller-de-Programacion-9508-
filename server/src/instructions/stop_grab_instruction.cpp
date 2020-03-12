#include "../../include/instructions/stop_grab_instruction.h"
#include "../../include/bodies/chell/chell.h"

StopGrabInstruction::StopGrabInstruction(Chell *chell):
    chell(chell) {
}

void StopGrabInstruction::execute() {
    chell->releaseGrab();
}
