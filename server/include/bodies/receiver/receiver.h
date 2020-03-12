#ifndef __RECEIVER_H__
#define __RECEIVER_H__

#include "../body.h"
#include "../../world.h"
#include "../../../../server/include/boolean_suppliers/boolean_supplier.h"
#include "../../../../server/include/bodies/gate/gateable.h"

class Bullet;
class Gate;
class Chell;

class Receiver: public Body, public Gateable {
private:
    bool is_on;
    Gate *gate;
    const float WIDHT = 2.00;
    const float HEIGHT = 2.00;

public:
    /* Instancia un receptor en world en la posicion (x, y) */
    Receiver(World *world, float x, float y);

    ~Receiver();

    /* Indica si el receptor esta activado */
    bool isOn() const;

    /* Activa al receptor */
    void turnOn();

    /* Asigna una compuerta al receptor */
    void setGate(Gate *gate);

    /* Indica si el receptor esta activado */
    virtual bool getAsBoolean() const;

    /* Crea una update con el comando indicado */
    virtual Update createUpdate(COMMAND command) const;

    /* Maneja el inicio de contacto con otro cuerpo */
    virtual void handleBeginContactWith(Body *other_body, b2Contact *contact);

    /* Activa al receptor si es colisionado por una bala */
    virtual void handleBeginContactWith(Bullet *bullet, b2Contact *contact);

    /* Aterriza a chell */
    virtual void handleBeginContactWith(Chell *chell, b2Contact *contact);

    /* Maneja el fin de contacto con otro cuerpo */
    virtual void handleEndContactWith(Body *other_body, b2Contact *contact);
};

#endif
