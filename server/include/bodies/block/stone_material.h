#ifndef __STONE_MATERIAL_H__
#define __STONE_MATERIAL_H__

#include "material.h"

class DiagonalShape;
class SquareShape;

class Bullet;

class StoneMaterial: public Material {
public:
    virtual ENTITY createEntityWithShape(DiagonalShape *diagonal_shape) override;

    virtual ENTITY createEntityWithShape(SquareShape *square_shape) override;

    /* Indica si se puede abrir un portal sobre la superficie de metal */
    virtual bool canOpenPortalOnSurface() const;

    /* Maneja el inicio de contacto con una bala */
    virtual void handleBeginContactWith(
        Bullet *bullet, b2Contact *contact) const;
};

#endif
