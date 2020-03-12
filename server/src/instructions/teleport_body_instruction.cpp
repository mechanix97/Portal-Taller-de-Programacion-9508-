#include "../../include/instructions/teleport_body_instruction.h"
#include "../../../libs/Box2D-master/Box2D/Common/b2Math.h"
#include "../../../server/include/bodies/body.h"

TeleportBodyInstruction::TeleportBodyInstruction(
    Body *body, b2Vec2 v, b2Vec2 pos, float angle):
    body(body), v(v), pos(pos), angle(angle) {
}

void TeleportBodyInstruction::execute() {
    body->setLinearVelocity(v);
    body->setTransform(pos, angle);
}
