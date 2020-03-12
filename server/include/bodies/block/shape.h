#ifndef __SHAPE_H__
#define __SHAPE_H__

#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../common/include/types.h"

class Material;

class Shape {
public:
    virtual b2PolygonShape giveShape(float half_with, float half_height) = 0;
    virtual ENTITY createEntityWithMaterial(Material *material) = 0;
    virtual ~Shape();
};

#endif
