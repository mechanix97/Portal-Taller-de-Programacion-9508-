#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "../../../../common/include/update.h"
#include "../../../../common/include/types.h"
#include "../../libs/Box2D-master/Box2D/Common/b2Math.h"

class DiagonalShape;
class SquareShape;
class Portal;

class Bullet;
class b2Contact;

class Material {
public:
    /* Libera los recursos utilizados */
    virtual ~Material();

    virtual ENTITY createEntityWithShape(DiagonalShape *diagonal_shape) = 0;

    virtual ENTITY createEntityWithShape(SquareShape *square_shape) = 0;

    /* Indica si se puede abrir un portal sobre el material */
    virtual bool canOpenPortalOnSurface() const = 0;

    /* Maneja el inicio de contacto con una bala */
    virtual void handleBeginContactWith(
        Bullet *bullet, b2Contact *contact) const = 0;
};

#endif
