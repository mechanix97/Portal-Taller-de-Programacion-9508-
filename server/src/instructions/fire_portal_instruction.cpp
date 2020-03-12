#include "../../include/instructions/fire_portal_instruction.h"
#include "../../include/bodies/chell/chell.h"
#include <iostream>

FirePortalInstruction::FirePortalInstruction(
    Chell *chell, uint8_t number,
    float x, float y):
    chell(chell), number(number),
    x(x / (float)ZOOM_FACTOR), y(y / (float)ZOOM_FACTOR) {
}

void FirePortalInstruction::execute() {
    if (number == 1) {
        chell->firePortalOne(x, y);
    } else {
        chell->firePortalTwo(x, y);
    }
}
