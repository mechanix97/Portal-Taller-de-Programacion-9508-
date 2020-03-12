#ifndef __LAUNCH_H__
#define __LAUNCH_H__

#include "../body.h"
#include "../../../../common/include/types.h"
#include "../../../../common/include/update.h"
#include <cstdint>

class World;
class Bullet;
class Chell;

class Launcher: public Body {
private:
    DIRECTION direction;
    uint32_t counter;
    const float WIDTH = 2.00;
    const float HEIGHT = 2.00;
    const float MIN_CREATE_DISTANCE = 2;

public:
    /* Instancia un launcher de id 'body_id' sobre world en la
     * posicion (x, y) apuntado hacia la direccion dada. */
    Launcher(
        World *world,
        float x, float y,
        DIRECTION direction);

    ~Launcher();

    /* Crea una update con el comando indicado */
    virtual Update createUpdate(COMMAND command) const;

    /* Maneja el inicio de contacto con otro cuerpo */
    virtual void handleBeginContactWith(Body *other_body, b2Contact *contact);

    /* Mata a bullet */
    virtual void handleBeginContactWith(
        Bullet *bullet, b2Contact *contact) override;

    /* Aterriza a chell */
    virtual void handleBeginContactWith(
        Chell *chell, b2Contact *contact) override;

    /* Maneja el fin de contacto con otro cuerpo */
    virtual void handleEndContactWith(Body *other_body, b2Contact *contact);

    /* Aplica una accion dependiendo de su estado */
    virtual void applyStateAction() override;

    /* Dispara una bala en la direccion del launcher */
    Bullet *fireABullet();
};

#endif
