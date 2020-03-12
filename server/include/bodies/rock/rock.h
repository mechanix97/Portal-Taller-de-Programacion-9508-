#ifndef __ROCK_H__
#define __ROCK_H__

#include "../body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include <cstdint>

class World;
class Laser;
class Chell;
class Bullet;
class Portal;

class Rock: public Body {
private:
    Chell *chell;
    const float WIDTH = 0.5;
    const float HEIGHT = 0.5;

public:
    /* Instancia una roca de id 'body_id' sobre b2orld en la
     * posicion (x, y) */
    Rock(World *world, float x, float y);

    /* Libera los recursos utilizados */
    ~Rock();

    /* Devuelve un puntero a chell si esta siendo tomada, en caso contrario
     * devuelve nullptr */
    Chell *getChell() const;

    /* Indica si fue tomado por alguna chell */
    bool isGrabbed() const;

    /* Es tomado por chell */
    void beGrabbedBy(Chell *chell);

    /* Se libera de chell si fue tomado */
    void tryReleaseFromChell();

    /* Devuelve una update de la roca */
    virtual Update createUpdate(COMMAND command) const;

    /* Maneja el inicio de contacto con otro cuerpo */
    virtual void handleBeginContactWith(Body *other_body, b2Contact *contact);

    /* Destruye una bala */
    virtual void handleBeginContactWith(Bullet *bullet, b2Contact *contact);

    /* Es tomado por chell si esta en grabbing mode */
    virtual void handleBeginContactWith(Chell *chell, b2Contact *contact) override;

    /* Detruye a la roca */
    virtual void handleBeginContactWith(Laser *laser, b2Contact *contact) override;

    /* Teletransporta a la roca */
    virtual void handleBeginContactWith(Portal *portal, b2Contact *contact) override;

    /* Maneja el fin de contacto con otro cuerpo */
    virtual void handleEndContactWith(Body *other_body, b2Contact *contact);
};

#endif
