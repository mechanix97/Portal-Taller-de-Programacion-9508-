#include "../../include/instructions/transform_body_instruction.h"
#include "../../include/bodies/body.h"
#include "../../include/world.h"
#include "../../../libs/Box2D-master/Box2D/Common/b2Math.h"


TransformBodyInstruction::TransformBodyInstruction(
    Body *body, b2Vec2 pos, float angle):
    body(body), pos(pos), angle(angle) {
}


void TransformBodyInstruction::execute() {
    body->setTransform(pos, angle);
}
