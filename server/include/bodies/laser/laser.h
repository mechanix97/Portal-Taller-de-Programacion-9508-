#ifndef __LASER_H__
#define __LASER_H__

#include "../body.h"
#include "../../../../common/include/types.h"

class Rock;

class Laser: public Body {
private:
    ANGLE angle;
    const float WIDTH  = 2.00;
    const float HEIGHT = 0.10;

public:
    /* Instancia un laser en world en (x, y) con un cierto angulo en grados.
     * Pre: Los unicos angulos permitidos son ANGLE_000 y ANGLE_090 */
    Laser(World *world, float x, float y, ANGLE angle);

    /* Crea una update con el comando indicado */
    virtual Update createUpdate(COMMAND command) const;

    /* Maneja el inicio de contacto con otro cuerpo */
    virtual void handleBeginContactWith(Body *body, b2Contact *contact);

    /* Desintegra una roca */
    virtual void handleBeginContactWith(Rock *rock, b2Contact *contact) override;

    /* Maneja el fin de contacto con otro cuerpo */
    virtual void handleEndContactWith(Body *body, b2Contact *contact);
};

#endif
