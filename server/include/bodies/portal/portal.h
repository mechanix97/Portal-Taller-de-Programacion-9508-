#ifndef __PORTAL_H__
#define __PORTAL_H__

#define NPORTAL1 1
#define NPORTAL2 2

#include "../body.h"

class World;
class Bullet;
class Chell;
class Rock;

class Portal: public Body {
private:
    const b2Vec2 normal;
    Portal *opposite;
    const float WIDTH = 2.20;
    const float HEIGHT = 0.30;

public:
    /* Instancia un portal de numero 'portal_number' en world en la posicion
     * pos con normal 'normal' */
    Portal(World *world, uint8_t portal_number, b2Vec2 pos, b2Vec2 normal);

    /* Libera los recursos utilizados */
    ~Portal();

    /* Teletransporta a body al portal indicando si debe cambiar el
     * el angulo de body en caso de ser necesario.
     * d es la distancia de separacion al portal al aparecer.
     * alfa es el angulo de la  */
    void teleportBody(Body *body, bool change_angle, float d, float alfa) const;

    /* Teletransporta a body al portal opuesto en caso de no ser nullptr e
     * indicando si debe cambiar el angulo de body en caso de ser necesario.
     * d es la distancia de separacion al portal al aparecer.
     * v es la velocidad linear de */
    void teleportToOppositePortal(Body *body, bool change_angle, float d) const;

    /* Asigna un portal opuesto */
    void setOppositePortal(Portal *opposite);

    /* Crea una update con el comando indicado */
    virtual Update createUpdate(COMMAND command) const;

    /* Maneja el inicio de contacto con otro cuerpo */
    virtual void handleBeginContactWith(Body *body, b2Contact *contact);

    /* Maneja el fin de contacto con otro cuerpo */
    virtual void handleEndContactWith(Body *body, b2Contact *contact);

    /* Teletransporta una bala */
    virtual void handleBeginContactWith(
        Bullet *bullet, b2Contact *contact) override;

    /* Teletransporta a chell */
    virtual void handleBeginContactWith(
        Chell *chell, b2Contact *contact) override;

    /* Teletransporta una roca */
    virtual void handleBeginContactWith(
        Rock *rock, b2Contact *contact) override;
};

#endif
