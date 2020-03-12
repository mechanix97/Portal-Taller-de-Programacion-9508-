#ifndef __PORTAL_GUN_H__
#define __PORTAL_GUN_H__

#include <cstdint>
#include "../../../../libs/Box2D-master/Box2D/Common/b2Math.h"
#include "../../../include/ray_cast_closest_body_callback.h"
#include "../../common/include/types.h"



class Portal;
class Chell;

class PortalGun {
private:
    Chell *chell;
    Portal *portal_one;
    Portal *portal_two;

public:
    /* Instancia una portal gun para chell */
    PortalGun(Chell *chell);

    /* Libera los recursos utilizados */
    ~PortalGun();

    /* Resetea los portales */
    void resetPortals();

    /* Devuelve un puntero al primer portal */
    Portal *getPortalOne() const;

    /* Devuelve un puntero al segundo portal */
    Portal *getPortalTwo() const;

    /* Dispara el primer portal a (x, y) */
    void firePortalOne(float x, float y);

    /* Dispara el segundo portal a (x, y) */
    void firePortalTwo(float x, float y);

private:
    /* Destruye un portal.
     * En caso de ser nullptr no hace nada. */
    void destroyPortal(Portal *&portal);

    /* Dispara un portal 'portal_number' a (x, y).
     * De ser creado devuelve su puntero, en caso contrario devuelve nullptr */
    Portal *firePortal(uint8_t portal_number, b2Vec2 pos);

    /* Asigna un portal opuesto */
    void setOppositePortals(Portal *portal, Portal *opposite);

    /* Intenta enviar un update de portal a world.
     * Si portal es nulo no hace nada.*/
    void addPortalUpdateToWorld(Portal *portal, COMMAND command);
};

#endif
