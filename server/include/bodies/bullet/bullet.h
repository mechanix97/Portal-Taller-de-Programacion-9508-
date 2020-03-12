#ifndef __BULLET_H__
#define __BULLET_H__

#include "bullet_def.h"
#include "../body.h"
#include "../../../include/world.h"
#include "../../../../common/include/types.h"
#include "../../../../common/include/update.h"
#include <cstdint>

class Block;
class Launcher;
class Receiver;
class Portal;
class Chell;
class Rock;

class Bullet: public Body {
private:
    DIRECTION direction;
    unsigned int life_steps;
    BulletDef def;
    bool is_destroyed;
    const float WIDTH = 1.00;
    const float HEIGHT = 0.60;
    const float DENSITY = 1;

public:
    /* Instancia una bala en world en la posicion (x, y) moviendose con
     * direccion 'direction' */
    Bullet(World *world, float x, float y, DIRECTION direction);

    /* Libera los recursos utilizados */
    ~Bullet();

    /* Crea una update con el comando indicado */
    virtual Update createUpdate(COMMAND command) const;

    /* Maneja el inicio de contacto con otro cuerpo */
    virtual void handleBeginContactWith(Body *other_body, b2Contact *contact);

    /* Muere al chocar con un bloque */
    virtual void handleBeginContactWith(
       Block *block, b2Contact *contact) override;

    /* Muere al chocar con otra bala */
    virtual void handleBeginContactWith(
       Bullet *bullet, b2Contact *contact) override;

    /* Mata a chell. */
    virtual void handleBeginContactWith(
       Chell *chell, b2Contact *contact) override;

    /* Muere al chocar con un lanzador */
    virtual void handleBeginContactWith(
       Launcher *launcher, b2Contact *contact) override;

    /* Transportaa bullet al otro portal si esta activo */
     virtual void handleBeginContactWith(
        Portal *receiver, b2Contact *contact) override;

    /* Muere y activa el receptor */
    virtual void handleBeginContactWith(
        Receiver *receiver, b2Contact *contact) override;

    /* Muere y activa el receptor */
    virtual void handleBeginContactWith(
       Rock *rock, b2Contact *contact) override;

    /* Maneja el fin de contacto con otro cuerpo */
    virtual void handleEndContactWith(Body *other_body, b2Contact *contact);

    /* Incrementa su contador de life steps.
     * Si supera MAX_LIFE_STEPS es eliminada de world. */
    virtual void applyStateAction() override;
};

#endif
