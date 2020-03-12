#include "../../include/instructions/set_linear_velocity_instruction.h"
#include "../../../libs/Box2D-master/Box2D/Common/b2Math.h"
#include "../../include/bodies/body.h"

SetLinearVelocityInstruction::SetLinearVelocityInstruction(
    Body *body, b2Vec2 v):
    body(body), v(v) {
}

void SetLinearVelocityInstruction::execute() {
    body->setLinearVelocity(v);
}
