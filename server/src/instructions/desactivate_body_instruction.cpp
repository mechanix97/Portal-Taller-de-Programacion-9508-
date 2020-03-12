#include "../../include/instructions/desactivate_body_instruction.h"
#include "../../../server/include/bodies/body.h"

DesactivateBodyInstruction::DesactivateBodyInstruction(Body *body):
    body(body) {
}

void DesactivateBodyInstruction::execute() {
    body->desactivate();
}
