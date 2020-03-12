#include "../../include/instructions/jig_instruction.h"
#include "../../include/bodies/chell/chell.h"
#include "../../include/world.h"

JigInstruction::JigInstruction(Chell *chell):
    chell(chell) {
}

void JigInstruction::execute() {
    this->chell->jig();
    Update update = this->chell->createUpdate(COMMAND::UPDATE_COMMAND);
    this->chell->getWorld()->addUpdate(update);
}
