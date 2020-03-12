#include "../../../include/bodies/block/square_shape.h"
#include "../../../include/bodies/block/material.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../common/include/types.h"


b2PolygonShape SquareShape::giveShape(float width, float height) {
    b2PolygonShape boxShape;
    boxShape.SetAsBox(width/2, height/2);
    return boxShape;
}

ENTITY SquareShape::createEntityWithMaterial(Material *material) {
    return material->createEntityWithShape(this);
}
