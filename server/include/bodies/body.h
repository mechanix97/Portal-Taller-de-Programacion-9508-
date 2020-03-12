#ifndef __BODY_H__
#define __BODY_H__

#include "../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../libs/Box2D-master/Box2D/Dynamics/Contacts/b2Contact.h"
#include "../../../common/include/types.h"
#include "../../../common/include/update.h"
#include <cstdint>

class World;

class Acid;
class Block;
class Bullet;
class Button;
class Chell;
class Gate;
class Rock;
class Launcher;
class Receiver;
class Portal;
class Cake;
class Laser;

class Body {
protected:
    const uint32_t BODY_ID;
    World *world;
    const ENTITY entity;
    bool is_destroyed;
    b2Body *b2body;

public:
    Body(World *world, ENTITY entity);

    /* Libera los recursos utilizados */
    virtual ~Body();

    /* Indica si el cuerpo fue destruido */
    virtual bool isDestroyed() const;

    /* Intenta destruir el cuerpo si no fue destruido */
    virtual void tryDestroy();

    /* Obtiene la normal del contacto */
    b2Vec2 getNormal(b2Contact *contact) const;

    /* Indica si body esta en condiciones de crear una update */
    bool isUpdatable() const;

    /* Devuelve un puntero a b2body */
    b2Body *getB2Body();

    /* Indica si body puede abrir un portal en su superficie */
    virtual bool canOpenPortalOnSurface() const;

    /* Devuelve el angulo */
    float getAngle() const;

    /* Settea la velocidad lineal */
    void setLinearVelocity(b2Vec2 v);

    /* Devuelve la velocidad lineal */
    b2Vec2 getLinearVelocity() const;

    /* Indica si el body esta activo */
    bool isActive() const;

    /* Activa el cuerpo. Los cuerpos activos aparecen en la simulacio. */
    void activate();

    /* Desactiva el cuerpo. Los cuerpos desactivados no aparecen en la
     * simulacion. */
    void desactivate();

    /* Mueve al cuerpo a la posicion pos (desde el origen de world ) y
     * rotado en un angulo angle */
    void setTransform(b2Vec2 pos, float angle);

    /* Devuelve world */
    World *getWorld() const;

    /* Posiciona al cuerpo en la nueva posicion */
    void setPosition(b2Vec2 pos);

    /* Devuelve la posicion del cuerpo */
    b2Vec2 getPosition() const;

    /* Devuelve la magnitud de la velocidad */
    float getMagnitudOfVelocity() const;

    /* Devuelve la posicion x */
    float getPosX() const;

    /* Devuelve la posicion y */
    float getPosY() const;

    /* Crea una update con el comando indicado */
    virtual Update createUpdate(COMMAND command) const = 0;

    /* Maneja el inicio de contacto con otro cuerpo */
    virtual void handleBeginContactWith(Body *body, b2Contact *contact) = 0;

    /* Maneja el fin de contacto con otro cuerpo */
    virtual void handleEndContactWith(Body *body, b2Contact *contact) = 0;

    /* Devuelve un identificador del cuerpo */
    uint32_t getBodyId() const;

    /* Indica si el cuerpo esta despierto */
    bool isAwake() const;

    /* Despierta al cuerpo */
    void wakeUp();

    /* Duerme al cuerpo */
    void putToSleep();

    /* Devuelve la masa del cuerpo */
    float getMass() const;

    /* Aplica una accion sobre el cuerpo dependiendo de su estado */
    virtual void applyStateAction();

    virtual void handleBeginContactWith(Acid *acid, b2Contact *contact);

    virtual void handleBeginContactWith(Block *block, b2Contact *contact);

    virtual void handleBeginContactWith(Bullet *bullet, b2Contact *contact);

    virtual void handleBeginContactWith(Button *button, b2Contact *contact);

    virtual void handleBeginContactWith(Cake *cake, b2Contact *contact);

    /* Deja que el inicio de contacto sea manejado por chell */
    virtual void handleBeginContactWith(Chell *chell, b2Contact *contact);

    virtual void handleBeginContactWith(Gate *gate, b2Contact *contact);

    virtual void handleBeginContactWith(Laser *laser, b2Contact *contact);

    virtual void handleBeginContactWith(Launcher *launcher, b2Contact *contact);

    virtual void handleBeginContactWith(Portal *portal, b2Contact *contact);

    virtual void handleBeginContactWith(Receiver *receiver, b2Contact *contact);

    virtual void handleBeginContactWith(Rock *rock, b2Contact *contact);

    /* Maneja el fin de contacto con acid */
    virtual void handleEndContactWith(Acid *acid, b2Contact *contact);

    virtual void handleEndContactWith(Block *block, b2Contact *contact);

    virtual void handleEndContactWith(Bullet *bullet, b2Contact *contact);

    virtual void handleEndContactWith(Button *button, b2Contact *contact);

    virtual void handleEndContactWith(Cake *cake, b2Contact *contact);

    virtual void handleEndContactWith(Chell *chell, b2Contact *contact);

    virtual void handleEndContactWith(Gate *gate, b2Contact *contact);

    virtual void handleEndContactWith(Launcher *launcher, b2Contact *contact);

    virtual void handleEndContactWith(Portal *portal, b2Contact *contact);

    virtual void handleEndContactWith(Receiver *receiver, b2Contact *contact);

    virtual void handleEndContactWith(Rock *rock, b2Contact *contact);
};

#endif
