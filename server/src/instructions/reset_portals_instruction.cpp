#include "../../include/instructions/reset_portals_instruction.h"

#include "../../include/instructions/instruction.h"
#include "../../include/bodies/chell/chell.h"


ResetPortalsInstruction::ResetPortalsInstruction(Chell *chell):
    chell(chell) {
}

void ResetPortalsInstruction::execute() {
    this->chell->getPortalGun()->resetPortals();
}
