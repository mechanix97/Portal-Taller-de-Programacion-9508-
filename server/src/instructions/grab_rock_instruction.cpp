#include "../../include/instructions/grab_rock_instruction.h"

#include "../../include/bodies/chell/chell.h"
#include "../../include/bodies/rock/rock.h"

GrabRockInstruction::GrabRockInstruction(Chell *chell, Rock *rock):
    chell(chell),
    rock(rock) {
}

void GrabRockInstruction::execute() {
    chell->grabRock(rock);
}
