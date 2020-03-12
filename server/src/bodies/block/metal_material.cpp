#include "../../../include/bodies/block/metal_material.h"

#include "../../../include/bodies/block/diagonal_shape.h"
#include "../../../include/bodies/block/square_shape.h"
#include "../../../include/bodies/portal/portal.h"
#include "../../../include/world.h"
#include "../../../include/instructions/set_linear_velocity_instruction.h"
#include "../../../../common/include/types.h"
#include <cmath>
#include <iostream>
#include "../../../include/bodies/bullet/bullet.h"
#include "../../libs/Box2D-master/Box2D/Collision/b2Collision.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/Contacts/b2Contact.h"
#include "../../../include/math_ext.h"

ENTITY MetalMaterial::createEntityWithShape(DiagonalShape *diagonal_shape) {
    return ENTITY::METAL_TRIAG_BLOCK;
}

ENTITY MetalMaterial::createEntityWithShape(SquareShape *square_shape) {
    return ENTITY::METAL_BLOCK;
}

bool MetalMaterial::canOpenPortalOnSurface() const {
    return true;
}

void MetalMaterial::handleBeginContactWith(
    Bullet *bullet, b2Contact *contact) const {
    b2Vec2 normal = bullet->getNormal(contact);
    normal.Normalize();
    b2Vec2 v = bullet->getLinearVelocity();
    b2Vec2 new_v = MathExt::reflect(normal, v);
    if (normal.x < 0.001 && normal.y < 0.001) {
        return;
    }
    World *world = bullet->getWorld();
    world->addInstruction(new SetLinearVelocityInstruction(bullet, new_v));
}
