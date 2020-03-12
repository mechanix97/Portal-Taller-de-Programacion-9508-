#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "../body.h"
#include "shape.h"
#include "material.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../common/include/update.h"
#include "../../../../common/include/types.h"
#include "block_def.h"

#include <cstdint>

class World;

class Shape;
class SquareShape;
class DiagonalShape;

class Material;
class MetalMaterial;
class StoneMaterial;

class Chell;
class Button;
class Gate;
class Rock;
class Bullet;
class Portal;

class Block: public Body {
private:
    ORIENTATION orientation;
    Shape *shape;
    Material *material;
    BlockDef def;
    const float WIDTH     = 2.00;
    const float HEIGHT    = 2.00;
    const float DENSITY   = 1;

public:
    /* Instancia un block de id 'body_id' sobre world en la posicion (x, y)
     * de shape y material asignado.
     * Al liberarse el block tambien se libera shape y material.
     * def contiene constantes para block. */
    Block(World *world,
          float x, float y, ORIENTATION orientation,
          Shape *shape, Material *material);

    /* Libera los recursos utilizados */
    ~Block();

    /* Indica si puede abrir portales en su superficie */
    virtual bool canOpenPortalOnSurface() const override;

    /* Devuelve una update del bloque */
    virtual Update createUpdate(COMMAND command) const;

    /* Maneja el inicio de contacto con body */
    virtual void handleBeginContactWith(Body *other_body, b2Contact *contact);

    /* Maneja el fin de contacto con otro cuerpo */
    virtual void handleEndContactWith(Body *other_body, b2Contact *contact);

    /* Maneja el inicio de contacto conuna bala */
    virtual void handleBeginContactWith(Bullet *bullet, b2Contact *contact) override;

    virtual void handleBeginContactWith(Chell *chell, b2Contact *contact) override;

};

#endif
