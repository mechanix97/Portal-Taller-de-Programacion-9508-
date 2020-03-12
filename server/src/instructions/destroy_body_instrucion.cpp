#include "../../include/instructions/destroy_body_instruction.h"
#include "../../include/bodies/body.h"
#include "../../include/world.h"
#include "../../common/include/update.h"

DestroyBodyInstruction::DestroyBodyInstruction(Body *body):
    body(body) {
}

void DestroyBodyInstruction::execute() {
    World *world = body->getWorld();
    world->destroyBody(body);
}
