#include "../../include/instructions/press_grab_instruction.h"
#include "../../include/bodies/chell/chell.h"

PressGrabInstruction::PressGrabInstruction(Chell *chell):
    chell(chell) {
}

void PressGrabInstruction::execute() {
    chell->pressGrab();
}
